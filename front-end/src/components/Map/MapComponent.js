import React from "react";
import { Link } from "react-router-dom";
// Map
import { GoogleMap, useJsApiLoader, Marker } from "@react-google-maps/api";
import bathrooms from "../../pages/Home/data/bathrooms.json";
import bathroomIcon from "../../assets/restroom-sign-svgrepo-com-white.svg";
import currentLocationIcon from "../../assets/current-location.svg";

import unisexBathroomIcon from "../../assets/restroom-sign-svgrepo-com-white.svg";
import menBathroomIcon from "../../assets/Pictograms-nps-accommodations-mens-restroom.svg";
import womenBathroomIcon from "../../assets/Pictograms-nps-accommodations-womens_restroom.svg"
// View Bathroom Drawer
import Drawer from "@mui/material/Drawer";
import { Button, IconButton } from "@mui/material";
import CloseIcon from "@mui/icons-material/Close";

// Rating in bathroom drawer
import {
  Link as RouterLink,
  LinkProps as RouterLinkProps,
  MemoryRouter,
} from 'react-router-dom';
import RatingList from "../RatingList";
export class MapComponent extends React.Component {

  constructor(props) {
    super(props);
    this.state = {
      Washrooms: null,
      Buildings: null,
      selectedBathroom: null,
      drawerOpen: false,
      mapWidth: "100vw",
      loaded: false,
      rathings: null,
      userLocation: null
    };
    this.containerStyle = {
      width: this.state.mapWidth,
      height: "100vh",
    };
    this.defaultProps = {
      center: {
        lat: 43.0096,
        lng: -81.2737,
      },
      zoom: 15,
    };
    this.LinkBehavior = React.forwardRef((props, ref) => (
      <RouterLink ref={ref} to="/material-ui/getting-started/installation/" {...props} />
    ));

    
  }

  componentDidMount() {
    this.fetchData();
    // get user coordinates
    console.log("GETTING USER COORDINATES")
    if (navigator.geolocation) {
      navigator.geolocation.getCurrentPosition(this.gotLocation, this.error);
    } else {
      console.log("Geolocation not supported");
    }

  }

  async fetchData() {
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
    ).catch((err)=>{
      console.log(err)
      alert("error fetching data")
    });
    const data = await res.json();
    const res2 = await fetch(
      "http://localhost:8000/buildings/offset/0/limit/50",
      {
        method: "get",
        headers: {
          "Content-type": "application/json",
          Accept: "*/*",
          "Accept-Encoding": "gzip, deflate, br",
          Connection: "keep-alive",
        },
      }
    ).catch((err)=>{
      console.log(err)
      alert("error fetching data")
    });
    const data2 = await res2.json();
      const res3 = await fetch(
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
    ).catch((err)=>{
      console.log(err)
      alert("error fetching data")
    });
    const data3 = await res3.json();
    

    this.setState({
      Washrooms: data.items,
      Buildings: data2.items,
      ratings: data3.items
    });
    // console.log(this.state);
    this.setState({ loaded: true });
  }

  setDrawerOpen = (open) => {
    this.setState({ drawerOpen: open });
  };

  setSelectedBathroom = (bathroom) => {
    this.setState({ selectedBathroom: bathroom });
  };

  setMapWidth = (width) => {
    this.setState({ mapWidth: width });
  };
  

  gotLocation = (position) => {
    const latitude = position.coords.latitude;
    const longitude = position.coords.longitude;
    console.log("USER COORDINATES")
    console.log(`Latitude: ${latitude}, Longitude: ${longitude}`);
    this.setState({userLocation: [latitude, longitude]})
  }

  error() {
    console.log("Unable to user location");
  }

  render() {
    return this.state.loaded ? (
      <div>
        {/* Map */}
        <GoogleMap
          mapref={this.mapRef}
          mapContainerStyle={this.containerStyle}
          center={this.defaultProps.center}
          zoom={17}
          onUnmount={this.onUnmount}
          options={{ mapId: "261e3d8414cdf367", disableDefaultUI: true }}
        >
          {this.state.Washrooms.map((bathroom) => {
            // console.log(bathroom);
            const lng = Number(bathroom.longitude);
            const lat = Number(bathroom.latitude);
            // console.log(lng, lat);
            return (
              <Marker
                id={bathroom.building}
                position={{
                  lat: lat,
                  lng: lng,
                }}
                icon={
                  (bathroom.gender === 'm') ? menBathroomIcon 
                    : (bathroom.gender === 'f') ? womenBathroomIcon 
                    : unisexBathroomIcon
                  }
                onClick={() => {
                  this.setSelectedBathroom(bathroom);
                  if (!this.state.drawerOpen) {
                    this.setDrawerOpen(true);
                    this.setMapWidth("65vw");
                  }
                }}
              />
            );
          })}
          {this.state.userLocation && 
          <Marker
            position={{
              lat: this.state.userLocation[0],
              lng: this.state.userLocation[1]
            }}
            icon={currentLocationIcon}
          />
          }
        </GoogleMap>

        {/* View Bathroom Window */}
        {this.state.selectedBathroom && (
          <Drawer
            anchor="right"
            open={this.state.drawerOpen}
            sx={{
              width: "35vw",
              flexShrink: 0,
              "& .MuiDrawer-paper": {
                width: "35vw",
                boxSizing: "border-box",
              },
            }}
            variant="persistent"
          >
            <div
              style={{
                paddingRight: "48px",
                paddingLeft: "48px",
                paddingTop: "60px",
                paddingBottom: "60px",
              }}
            >
              <IconButton
                onClick={() => {
                  this.setDrawerOpen(false);
                  this.setSelectedBathroom(null);
                  this.setMapWidth("100vw");
                }}
                sx={{ position: "absolute", top: "16px", right: "32px" }}
              >
                <CloseIcon />
              </IconButton>
              <h1>{this.state.selectedBathroom.building}</h1>
              <h3>{`Floor ${this.state.selectedBathroom.floor}, ${this.state.selectedBathroom.id}`}</h3>
              <br />
              <br />
              <h2>Information</h2>
              <p>{`Floor: ${this.state.selectedBathroom.floor}`}</p>
              <p>{`Gender: ${
                this.state.selectedBathroom.gender === "m"
                  ? "Male"
                  : this.state.selectedBathroom.gender === "f"
                  ? "Female"
                  : "All Gender"
              }`}</p>
              {this.state.selectedBathroom.gender === "m" &&
                `Urinals: ${this.state.selectedBathroom.urinalCount}`}
              <p>{`Stalls: ${this.state.selectedBathroom.stallCount}`}</p>
              <br />
              <br />
              <h2>Reviews</h2>
              <br />
              <RatingList bathroom={this.state.selectedBathroom} />
            </div>
          </Drawer>
        )}
      </div>
    ) : (
      <></>
    );
  }
}
