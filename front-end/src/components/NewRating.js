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
        console.log(user.user.id)

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
                userId: user.user.id
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
                <FormControl>
                    <FormLabel>Overall Experience Rating</FormLabel>
                    <Rating
                        name="overallRating"
                        value={inputs.overallRating}
                        onChange={handleChange}
                        required={true}
                    />
                    <FormLabel>Cleanliness Rating</FormLabel>
                    <Rating
                        name="cleanlinessRating"
                        value={inputs.cleanlinessRating}
                        onChange={handleChange}
                    />
                    <FormLabel>Additional Details</FormLabel>
                    <TextField
                        name="textReview"
                        multiline
                        rows={4}
                        value={inputs.textReview} 
                        onChange={handleChange}
                    />
                    <Button type='submit'>Submit</Button>
                </FormControl>
            </form>
        </div>
    )
}

export default NewRating