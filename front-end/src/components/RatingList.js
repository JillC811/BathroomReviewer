
import React, {useState} from 'react'
import { Link } from 'react-router-dom'

import {List, ListItem, ListItemText, ListItemAvatar} from '@mui/material';
import {Button, Divider, TextField} from '@mui/material'

//Ratings dropdown
import Rating from '@mui/material/Rating';

import Dialog from '@mui/material/Dialog';
import DialogActions from '@mui/material/DialogActions';
import DialogContent from '@mui/material/DialogContent';
import DialogContentText from '@mui/material/DialogContentText';
import DialogTitle from '@mui/material/DialogTitle';

import { useEffect } from 'react';

import {
  Link as RouterLink,
  LinkProps as RouterLinkProps,
  MemoryRouter,
} from 'react-router-dom';
import { StaticRouter } from 'react-router-dom/server';
import { useNavigate } from 'react-router-dom';
import { useSelector } from 'react-redux';

import './NewRating.css';


function RatingList(props) {
    const navigate = useNavigate()
    const bathroom = props.bathroom;
    const user = useSelector(state => state.user)
    const [ratings, setRatings] = useState([]);
    const [loaded, setLoaded] = useState(false);
    const [showDeleteModal, setShowDeleteModal] = useState(false);
    const [showEditModal, setShowEditModal] = useState(false);
    const [inputs, setInputs] = useState({
        overallRating: "",
        cleanlinessRating: "",
        textReview: ""
    })
   
    const handleDeleteModalOpen = () => {
        setShowDeleteModal(true);
    };

    const handleDeleteModalClose = () => {
        setShowDeleteModal(false);
    };

    const handleDeleteReview = (e) => {
        e.preventDefault();
        //delete backend call
    }

    const handleEditModalOpen = (rating) => {
        setShowEditModal(true);
        setInputs({
            overallRating: rating.overallRating,
            cleanlinessRating: rating.cleanlinessRating,
            textReview: rating.textReview
        })
    };

    const handleEditModalClose = () => {
        setShowEditModal(false);
    };

    const handleChange = (e) => {
        setInputs((prevState) => ({
            ...prevState,       //prev state is other fields already filled out in form
            [e.target.name] : e.target.value
        }))
    }

    const handleEditReview = (e) => {
        e.preventDefault();
        // fetch("http://localhost:8000/ratings", {
        //     method: "post",
        //     headers: {
        //         "Content-type": "application/json",
        //         Accept: "*/*",
        //         "Accept-Encoding": "gzip, deflate, br",
        //         Connection: "keep-alive",
        //     },
        //     body: JSON.stringify({
        //         bathroomId: Number(bathroom),
        //         overallRating: Number(inputs.overallRating),
        //         cleanlinessRating: Number(inputs.cleanlinessRating),
        //         textReview: inputs.textReview,
        //         uploader: user.user.username
        //     })
        // }).then((res) => {
        //     console.log(res);
        //     alert("Rating submitted!");
        //     navigate("/home");
        // })
    }

    useEffect(() => {
        const fetchRatings = async () => {
        const res = await fetch(
            "http://localhost:8000/ratings/offset/0/limit/50",
            {
            method: "get",
            headers: {
                "Content-type": "application/json",
                Accept: "*/*",
                "Accept-Encoding": "gzip, deflate, br",
                Connection: "keep-alive",
            },
            }
        );
        const data = await res.json();
        console.log(data);
        await setRatings(data.items);
        }

        Promise.all([fetchRatings()]).then(() => {
        console.log(ratings)
        setLoaded(true);
        })
        return () => {};
    }, []);

    const LinkBehavior = React.forwardRef((props, ref) => (
        <RouterLink ref={ref} to="/material-ui/getting-started/installation/" {...props} />
    ));

    return loaded ? (
        <>
        <Button component={LinkBehavior} to={{pathname: "/new-rating"}} state={{bathroom: Number(bathroom.id)}} variant="contained" color="primary"> Add Review </Button>
        <List>
        {ratings.length === 0 &&
            <ListItem>
            This bathroom has no reviews yet.
            </ListItem>
        }
        {ratings.map((rating) => {
            if(rating.bathroomId == bathroom.id){
                
            return (
                <>
                <ListItem alignItems="flex-start">
                    <ListItemText
                    primary={
                        <React.Fragment>
                        <h4>{rating.uploader}</h4>
                        </React.Fragment>
                    }
                    secondary={
                        <React.Fragment>
                        <div>
                            <h4>Overall Experience: </h4>
                            <Rating
                                name="overall rating"
                                value={rating.overallRating}
                                readOnly
                            />
                            <h4>Cleanliness: </h4>
                            <Rating
                            name="cleanliness"
                            value={rating.cleanlinessRating}
                            readOnly
                            />
                        </div>
                        <h4>Review: </h4>
                        <p>{rating.textReview}</p>
                        </React.Fragment>
                    }
                    />

                {/* {(user.username === rating.uploader || user.username === 'admin') ? ( */}
                    <div>
                    {/* Edit Review */}
                        <Button onClick={handleEditModalOpen}>Edit</Button>
                        <Dialog
                            fullWidth='true'
                            maxWidth='sm'
                            open={showEditModal}
                            onClose={handleEditModalClose}
                            aria-labelledby="alert-dialog-title"
                            aria-describedby="alert-dialog-description"
                        >
                            <form class="rating-form">
                                <DialogTitle id="alert-dialog-title">
                                {"Edit Current Review"}
                                </DialogTitle>
                                <DialogContent>
                                <div>
                                    <h4>Overall Experience: </h4>
                                    <Rating
                                        name="overall rating"
                                        defaultValue={rating.overallRating}
                                        value={inputs.overallRating}
                                    />
                                    <h4>Cleanliness: </h4>
                                    <Rating
                                        name="cleanliness"
                                        defaultValue={rating.cleanlinessRating}
                                        value={inputs.cleanlinessRating}
                                    />
                                </div>
                                <h4>Review: </h4>
                                <TextField
                                    name="textReview"
                                    multiline
                                    rows={4}
                                    defaultValue={rating.textReview}
                                    value={inputs.textReview} 
                                    onChange={handleChange}
                                />
                                <p>{rating.textReview}</p>
                                </DialogContent>
                                <DialogActions>
                                <Button onClick={handleEditModalClose}>Cancel</Button>
                                <Button type='submit' onClick={handleEditReview} autoFocus>
                                    Submit Edit
                                </Button>
                                </DialogActions>
                            </form>  
                        </Dialog>
                        
                    {/* Delete Review */}
                        <Button onClick={handleDeleteModalOpen}>Delete</Button>
                        <Dialog
                            open={showDeleteModal}
                            onClose={handleDeleteModalClose}
                            aria-labelledby="alert-dialog-title"
                            aria-describedby="alert-dialog-description"
                        >
                            <DialogTitle id="alert-dialog-title">
                            {"Are you sure you want to delete this review?"}
                            </DialogTitle>
                            <DialogContent>
                            <DialogContentText id="alert-dialog-description">
                                This review will be permanently deleted.
                            </DialogContentText>
                            </DialogContent>
                            <DialogActions>
                            <Button onClick={handleDeleteModalClose}>Cancel</Button>
                            <Button onClick={handleDeleteReview} autoFocus>
                                Delete
                            </Button>
                            </DialogActions>
                        </Dialog>
                        </div>
                {/* ) : (<></>)} */}
                </ListItem>
                <Divider variant="middle" component="li" />
                </>
            )
            }
        })}
        </List>         
    </>
    ) : (
        <h1>Loading...</h1>
    )
}

export default RatingList