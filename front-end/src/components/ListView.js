
import React, {useState} from 'react'
import { Link } from 'react-router-dom'

import {List, ListItem, ListItemText, ListItemAvatar} from '@mui/material';
import {Button, Divider, TextField} from '@mui/material'
import InputAdornment from '@mui/material/InputAdornment';

//Ratings dropdown
import {Accordion, AccordionSummary, AccordionDetails} from '@mui/material';
import Rating from '@mui/material/Rating';

import ManIcon from '@mui/icons-material/Man';
import WomanIcon from '@mui/icons-material/Woman';
import WcIcon from '@mui/icons-material/Wc';
import SearchIcon from "@mui/icons-material/Search";
import ExpandMoreIcon from '@mui/icons-material/ExpandMore';


import bathrooms from "../pages/Home/data/bathrooms.json"
import ratings from "../pages/Home/data/ratings.json"
import './ListView.css'

import { useEffect } from 'react';

import {
  Link as RouterLink,
  LinkProps as RouterLinkProps,
  MemoryRouter,
} from 'react-router-dom';
import { StaticRouter } from 'react-router-dom/server';


function ListView() {
  const [bathrooms, setBathrooms] = useState([]);
  const [searchQuery, setSearchQuery] = useState("");
  const [filteredBathrooms, setFilteredBathrooms] = useState(bathrooms)
  const [ratings, setRatings] = useState([]);
  const [loaded, setLoaded] = useState(false);

  const handleSearchBathroom = (e) => {
    const query = e.target.value;
    setSearchQuery(query);
    
    const filteredData = bathrooms.filter((bathroom) => bathroom.building.toLowerCase().includes(query.toLowerCase()));
    setFilteredBathrooms(filteredData);
  };

  useEffect(() => {
    const fetchBathrooms = async () => {
      const res = await fetch(
        "http://localhost:8000/bathrooms/offset/0/limit/50",
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
      await setBathrooms(data.items);
      await setFilteredBathrooms(data.items);
    };
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

    Promise.all([fetchBathrooms(), fetchRatings()]).then(() => {
      console.log(bathrooms, ratings)
      setLoaded(true);
    })
    return () => {};
  }, []);

  const LinkBehavior = React.forwardRef((props, ref) => (
    <RouterLink ref={ref} to="/material-ui/getting-started/installation/" {...props} />
  ));


  return loaded ? (
    <div class="center flex-box">
        <TextField
          className="text"
          value={searchQuery}
          onChange={handleSearchBathroom}
          label="Search for building"
          variant="outlined"
          placeholder="Search..."
          size="small"
          InputProps={{
            endAdornment: (
              <InputAdornment>
                <SearchIcon  style={{ fill: "blue" }}/>
              </InputAdornment>
            ),
          }}
        />

      <List>
        {filteredBathrooms.map((bathroom) => {
          return (
            <>
               <ListItem alignItems="flex-start">
                <ListItemAvatar>
                  {(bathroom.gender === 'm') ? <ManIcon fontSize="large"/> : (bathroom.gender === 'f') ? <WomanIcon fontSize="large"/> : <WcIcon fontSize="large"/>}
                </ListItemAvatar>
                <ListItemText
                  primary={<h2>{bathroom.building}</h2>}
                  secondary={
                    <React.Fragment>
                      <p>{`Floor: ${bathroom.floor}`}</p>
                      <p>{`Location: ${bathroom.latitude} , ${bathroom.longitude}`}</p>
                      <p>{`Gender: ${bathroom.gender === 'm' ? 'Male' : bathroom.gender === 'f' ? "Female" : 'All Gender'}`}</p>
                      {bathroom.gender === "Male" && `Urinals: ${bathroom.urinalCount}`}
                      <p>{`Stalls: ${bathroom.stallCount}`}</p>
                      
                      <br />
                      <Accordion>
                        <AccordionSummary
                          expandIcon={<ExpandMoreIcon />}
                          aria-controls="panel1a-content"
                          id="panel1a-header"
                        >
                          <h4>Reviews</h4>
                        </AccordionSummary>
                        <AccordionDetails>
                          <Button component={LinkBehavior} to={{pathname: "/new-rating"}} state={{bathroom: Number(bathroom.id)}} variant="contained" color="primary"
                          > Add Review </Button>
                          <List>
                            {bathroom.ratings.length === 0 &&
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
                                          <Rating
                                            name="overall rating"
                                            value={rating.overallRating}
                                            readOnly
                                          />
                                        }
                                        secondary={
                                          <React.Fragment>
                                            <div>
                                              <h4>Cleanliness: </h4>
                                              <Rating
                                                name="cleanliness"
                                                value={rating.cleanlinessRating}
                                                readOnly
                                                size="small"
                                              />
                                            </div>
                                            <h4>Review: </h4>
                                            <p>{rating.textReview}</p>
                                          </React.Fragment>
                                        }
                                      />
                                      </ListItem>
                                      <Divider variant="middle" component="li" />
                                  </>
                                )
                              }
                            })}
                          </List>
                        </AccordionDetails>
                      </Accordion>
                    </React.Fragment>
                  }
                />
                </ListItem>
                <Divider variant="inset" component="li" />
            </>
          )
        })}
      </List>
    </div>
  ) : (
    <h1>Loading...</h1>)
}

export default ListView