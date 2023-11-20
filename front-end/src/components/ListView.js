
import React, {useState} from 'react'

import List from '@mui/material/List';
import ListItem from '@mui/material/ListItem';
import Divider from '@mui/material/Divider';
import ListItemText from '@mui/material/ListItemText';
import ListItemAvatar from '@mui/material/ListItemAvatar';
import TextField from '@mui/material/TextField';
import InputAdornment from '@mui/material/InputAdornment';

//Ratings dropdown
import Accordion from '@mui/material/Accordion';
import AccordionSummary from '@mui/material/AccordionSummary';
import AccordionDetails from '@mui/material/AccordionDetails';
import Rating from '@mui/material/Rating';

import ManIcon from '@mui/icons-material/Man';
import WomanIcon from '@mui/icons-material/Woman';
import WcIcon from '@mui/icons-material/Wc';
import SearchIcon from "@mui/icons-material/Search";
import ExpandMoreIcon from '@mui/icons-material/ExpandMore';


import bathrooms from "../pages/Home/data/bathrooms.json"
import ratings from "../pages/Home/data/ratings.json"
import './ListView.css'


function ListView() {
  const [searchQuery, setSearchQuery] = useState("");
  const [filteredBathrooms, setFilteredBathrooms] = useState(bathrooms.bathrooms)

  const handleSearchBathroom = (e) => {
    const query = e.target.value;
    setSearchQuery(query);
    
    const filteredData = bathrooms.bathrooms.filter((bathroom) => bathroom.building.toLowerCase().includes(query.toLowerCase()));
    setFilteredBathrooms(filteredData);
  };


  return (
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
                      <p>{`Location: ${bathroom.location}`}</p>
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
                          <List>
                            {bathroom.ratings.length === 0 &&
                              <ListItem>
                                This bathroom has no reviews yet.
                              </ListItem>
                            }
                            {ratings.ratings.map((rating) => {
                              if(bathroom.ratings.includes(rating.id)){
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
  )
}

export default ListView