
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom'
import LoginPage from './pages/Login/LoginPage'
import HomePage from './pages/Home/HomePage'

import './App.css'

export default function App() {
    return (
        <Router>
          <Routes>
              <Route path="/" element={ <LoginPage /> } />
              <Route path="/home" element={ <HomePage /> } />
          </Routes>
        </Router>
    )
}