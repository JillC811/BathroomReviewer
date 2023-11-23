import React from 'react'

import GoogleMapReact from 'google-map-react'

export class Map extends React.Component {
    constructor(props){
        super(props);
        this.state = {
            Washrooms: [],
            Buildings: []
        };
    }
    componentDidMount(){
        this.fetchData();
    }

    async fetchData() {
        const res = await fetch(
            "http://localhost:8000/bathrooms/offset/0/limit/50",
            {
                method: "get",
                headers: {
                    "Content-type": "application/json",
                    "Accept": "*/*",
                    "Accept-Encoding": "gzip, deflate, br",
                    "Connection": "keep-alive"
                },

            }
        )
        const data = await res.json();
        const res2 = await fetch(
            "http://localhost:8000/buildings/offset/0/limit/50",
            {
                method: "get",
                headers: {
                    "Content-type": "application/json",
                    "Accept": "*/*",
                    "Accept-Encoding": "gzip, deflate, br",
                    "Connection": "keep-alive"
                },

            }
        )
        const data2 = await res2.json();
        console.log(
            data,
            data2
        )
        this.setState(
            {
                Washrooms: data.items,
                Buildings: data2.items
            })
    }
    render(){
        const defaultProps = {
            center: {
              lat: 43.0096,
              lng: -81.2737
            },
            zoom: 15
          };
        return (
            <div style={{ height: '100vh', width: '100%' }}>
                <GoogleMapReact
                    bootstrapURLKeys={{ key: "AIzaSyCMRG1d97TgMlhZraYKdMTQXI7G25yYy_M" }}
                    defaultCenter={defaultProps.center}
                    defaultZoom={defaultProps.zoom}
                >
                    {
                        this.state.Washrooms.map((washroom) => (
                            <div
                                lat={washroom.latitude}
                                lng={washroom.longitude}
                                text="washroom"
                            />
                        ))
                    }
                    {
                        this.state.Buildings.map((building) => (
                            <div
                                lat={building.latitude}
                                lng={building.longitude}
                                text="building"
                            />
                        ))
                    }
                </GoogleMapReact>
            </div>
        )
    }
}