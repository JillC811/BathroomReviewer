
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom'
import LoginPage from './pages/Login/LoginPage'
import HomePage from './pages/Home/HomePage'
import ListViewPage from './pages/Home/ListViewPage'
import NewRatingPage from './pages/Home/NewRatingPage'
import React from 'react'
import { UserContext } from './usercontext.js'

import './App.css'


export default function App() {
    const [user, setUser] = React.useState(null)
    return (
        <Router>
            <UserContext.Provider value={user}>
                <Routes>
                    <Route path="/" element={ <LoginPage /> } />
                    <Route path="/home" element={ <HomePage /> } />
                    <Route path="/list" element={ <ListViewPage /> } />
                    <Route path="/new-rating" element={ <NewRatingPage /> } />
                </Routes>
                </UserContext.Provider>
        </Router>
    )
}