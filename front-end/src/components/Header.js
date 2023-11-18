
import React from 'react'

import { Button } from '@mui/material'

import './Header.css'

function Header() {
  return (
    <div class='display-block'>
      <h1>Flushable</h1>
        <Button>Map View</Button>
        <Button>List View</Button>
    </div>
  )
}

export default Header