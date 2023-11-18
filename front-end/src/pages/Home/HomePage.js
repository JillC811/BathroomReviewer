import React from 'react'

import Header from '../../components/Header.js'
import Map from './Map.js'
import ListView from './ListView.js'

function HomePage() {
  return (
    <div>
      <Header />
      <ListView />
      {/* <Map /> */}
    </div>

  )
}

export default HomePage