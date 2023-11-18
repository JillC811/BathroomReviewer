
import React from 'react'
import { useNavigate } from 'react-router-dom'
import { Link } from 'react-router-dom'

import { Button } from '@mui/material'

import './Header.css'

function Header() {
  const navigate = useNavigate()

  return (
    <div class='display-block'>
      <h1>Flushable</h1>
        <Button component={Link} to="/home"> Map View </Button>
        <Button component={Link} to="/list">List View</Button>
    </div>
  )
}

export default Header