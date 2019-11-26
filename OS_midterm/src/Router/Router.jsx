import React from 'react'
import { BrowserRouter as Router, Route } from 'react-router-dom'
import { Load } from '../Layouts/Load'

const Home = () => (
    <div>Home</div>
)

const About = () => (
    <div>About</div>
)

const RouterList = () => (
    <Router>
        <Route exact path="/" component={Home} />
        <Route path="/load" component={Load} />
        <Route path="/about" component={About} />
    </Router>
)

export { RouterList }