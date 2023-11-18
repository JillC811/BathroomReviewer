
import React, {useState} from 'react'

import List from '@mui/material/List';
import ListItem from '@mui/material/ListItem';
import Divider from '@mui/material/Divider';
import ListItemText from '@mui/material/ListItemText';
import ListItemAvatar from '@mui/material/ListItemAvatar';
import TextField from '@mui/material/TextField';
import InputAdornment from '@mui/material/InputAdornment';

import ManIcon from '@mui/icons-material/Man';
import WomanIcon from '@mui/icons-material/Woman';
import WcIcon from '@mui/icons-material/Wc';
import SearchIcon from "@mui/icons-material/Search";

import bathrooms from "./data/bathrooms.json"
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
                      <h3>Reviews</h3>
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