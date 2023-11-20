import React from 'react'
import { Link } from 'react-router-dom'
// Map
import { GoogleMap, useJsApiLoader, Marker } from '@react-google-maps/api';
import bathrooms from "../pages/Home/data/bathrooms.json"
import bathroomIcon from "../assets/restroom-sign-svgrepo-com-white.svg"
// View Bathroom Drawer
import Drawer from '@mui/material/Drawer';
import { Button, IconButton } from '@mui/material';
import CloseIcon from '@mui/icons-material/Close';

// Rating in bathroom drawer
import ratings from "../pages/Home/data/ratings.json"
import List from '@mui/material/List';
import ListItem from '@mui/material/ListItem';
import Divider from '@mui/material/Divider';
import ListItemText from '@mui/material/ListItemText';
import Rating from '@mui/material/Rating';


function Map() {

  const [mapWidth, setMapWidth] = React.useState("100vw")
  
  const containerStyle = {
    width: mapWidth,
    height: "100vh"
  };

  const center = {
    lat: 43.00984030530936,
    lng: -81.2737550579818
  };

  const { isLoaded } = useJsApiLoader({
    id: 'google-map-script',
    googleMapsApiKey: process.env.REACT_APP_GOOGLE_KEY
  })

  const [map, setMap] = React.useState(null)

  const onUnmount = React.useCallback(function callback(map) {
    setMap(null)
  }, [])

  const [selectedBathroom, setSelectedBathroom] = React.useState(null)
  const [drawerOpen, setDrawerOpen] = React.useState(false)

  return isLoaded ? (
    <div>
      {/* Map */}
        <GoogleMap
          mapContainerStyle={containerStyle}
          center={center}
          zoom={17}
          onUnmount={onUnmount}
          options={{ mapId: "261e3d8414cdf367", disableDefaultUI: true }}
        >
          {bathrooms.bathrooms.map((bathroom) => {
            return (
            <Marker
              id={bathroom.building}
              position={{
                lat: bathroom.lat,
                lng: bathroom.lng
              }}
              icon={bathroomIcon}
              onClick={() => {
                setSelectedBathroom(bathroom)
                if (!drawerOpen) {
                  setDrawerOpen(true)
                  setMapWidth("65vw")
                }
              }}
            />
            )
          })}
        </GoogleMap>

      {/* View Bathroom Window */}
      {
      selectedBathroom && 
      <Drawer
        anchor="right"
        open={drawerOpen}
        sx={{
          width: "35vw",
          flexShrink: 0,
          '& .MuiDrawer-paper': {
            width: "35vw",
            boxSizing: 'border-box',
          },
        }}
        variant="persistent"
      >
        <div style={{
          paddingRight: "48px",
          paddingLeft: "48px",
          paddingTop: "60px",
          paddingBottom: "60px"
          }}>
            <IconButton 
              onClick={() => {
                  setDrawerOpen(false)
                  setSelectedBathroom(null)
                  setMapWidth("100vw")
              }}
              sx={{position: "absolute", top: "16px", right: "32px"}}
            >
              <CloseIcon />
            </IconButton>
            <h1>{selectedBathroom.building}</h1>
            <h3>{`Floor ${selectedBathroom.floor}, ${selectedBathroom.location}`}</h3>
            <br />
            <br />
            <h2>Information</h2>
            <p>{`Floor: ${selectedBathroom.floor}`}</p>
            <p>{`Location: ${selectedBathroom.location}`}</p>
            <p>{`Gender: ${selectedBathroom.gender === 'm' ? 'Male' : selectedBathroom.gender === 'f' ? "Female" : 'All Gender'}`}</p>
            {selectedBathroom.gender === "Male" && `Urinals: ${selectedBathroom.urinalCount}`}
            <p>{`Stalls: ${selectedBathroom.stallCount}`}</p>
            <br />
            <br />
            <h2>Reviews</h2>
            <br />
            <Button component={Link} to="/new-rating"> Add Review </Button>
            <List>
              {selectedBathroom.ratings.length === 0 &&
                <ListItem>
                  This bathroom has no reviews yet.
                </ListItem>
              }
              {ratings.ratings.map((rating) => {
                if(selectedBathroom.ratings.includes(rating.id)){
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
        </div>
      </Drawer>
      }
    </div>

  ) : <></>
}

export default React.memo(Map)