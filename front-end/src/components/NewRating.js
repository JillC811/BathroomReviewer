import React, {useState} from 'react'

import { Link, useLocation } from 'react-router-dom'

import Rating from '@mui/material/Rating';
import TextField from '@mui/material/TextField';
import Input from '@mui/material/Input';
import InputLabel from '@mui/material/InputLabel';
import { Button, FormControl, FormLabel } from '@mui/material';

import { useNavigate } from 'react-router-dom';
import { useSelector } from 'react-redux';

import './NewRating.css'

function NewRating() {

    const user = useSelector(state => state.user)

    const navigate = useNavigate()
    const [inputs, setInputs] = useState({
        overallRating: "",
        cleanlinessRating: "",
        textReview: ""
    })

    let { state } = useLocation();
    console.log(state);


    const[bathroom, setBathroom] = useState(state.bathroom);

    const handleChange = (e) => {
        setInputs((prevState) => ({
            ...prevState,       //prev state is other fields already filled out in form
            [e.target.name] : e.target.value
        }))
    }

    const handleSubmit = (e) => {
        e.preventDefault();     //prevents page from refreshing on submit
        console.log(inputs)
        if(user.user === null) {
            alert("Please log in to submit a rating!");
            navigate("/");
            return;
        }

        fetch("http://localhost:8000/ratings", {
            method: "post",
            headers: {
                "Content-type": "application/json",
                Accept: "*/*",
                "Accept-Encoding": "gzip, deflate, br",
                Connection: "keep-alive",
            },
            body: JSON.stringify({
                bathroomId: Number(bathroom),
                overallRating: Number(inputs.overallRating),
                cleanlinessRating: Number(inputs.cleanlinessRating),
                textReview: inputs.textReview,
                uploader: user.user.username
            })
        }).then((res) => {
            console.log(res);
            alert("Rating submitted!");
            navigate("/home");
        })
    }
    return(
        <div class="flex-box">
            <form onSubmit={handleSubmit} class="rating-form">
                    <h4>Overall Experience Rating</h4>
                    <Rating
                        name="overallRating"
                        value={inputs.overallRating}
                        onChange={handleChange}
                        required={true}
                    />
                    <h4>Cleanliness Rating</h4>
                    <Rating
                        name="cleanlinessRating"
                        value={inputs.cleanlinessRating}
                        onChange={handleChange}
                    />
                    <h4>Additional Details</h4>
                    <TextField
                        name="textReview"
                        multiline
                        rows={4}
                        value={inputs.textReview} 
                        onChange={handleChange}
                    />
                    <br />
                    <Button type='submit'>Submit</Button>
            </form>
        </div>
    )
}

export default NewRating