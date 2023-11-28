
import React from 'react'
import { Link } from 'react-router-dom'

import { Button } from '@mui/material'
import { useSelector } from 'react-redux'
import {useNavigate} from 'react-router-dom'
import { setUser } from '../store/userReducer'
import { useDispatch } from 'react-redux'


function Header() {
  const dispatch = useDispatch()
  const navigate  = useNavigate()
  const user = useSelector(state => state.user)
  const logout = () => {
    dispatch(setUser(null))
    navigate("/")
  }

  return (
      <div style={{display: 'block'}}>
        <h1>Flushable</h1>
        <div style={{display: 'flex', flexWrap: 'wrap'}}>
          <Button component={Link} to="/home"> Map View </Button>
          <Button component={Link} to="/list">List View</Button>
          {
            user.user=== null ?
            <Button component={Link} to="/">Sign In</Button> : 
            <React.Fragment>
              <div style={{flex: "1", display: "flex", justifyContent: 'space-between', paddingRight: "20px"}}>
                <Button onClick={logout}>Logout</Button>
                <h4 style={{}}>Logged in as {user.user.username}</h4>
              </div>
            </React.Fragment>
          }
        </div>
      </div>
  )
}

export default Header