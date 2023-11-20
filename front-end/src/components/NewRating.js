import React, {useState} from 'react'

import { Link } from 'react-router-dom'

import Rating from '@mui/material/Rating';
import TextField from '@mui/material/TextField';
import Input from '@mui/material/Input';
import InputLabel from '@mui/material/InputLabel';
import { Button, FormControl, FormLabel } from '@mui/material';

import './NewRating.css'

function NewRating() {
    const [inputs, setInputs] = useState({
        overallRating: "",
        cleanlinessRating: "",
        textReview: ""
    })

    const handleChange = (e) => {
        setInputs((prevState) => ({
            ...prevState,       //prev state is other fields already filled out in form
            [e.target.name] : e.target.value
        }))
    }

    const handleSubmit = (e) => {
        e.preventDefault();     //prevents page from refreshing on submit
        console.log(inputs)
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