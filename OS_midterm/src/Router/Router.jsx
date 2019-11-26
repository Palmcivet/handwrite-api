import React from 'react'
import { BrowserRouter as Router, Route, Link } from 'react-router-dom'
import Button from '@material-ui/core/Button'
import { ButtonGroup } from '@material-ui/core'
import { Load } from '../Layouts/Load'

const Home = () => (
    <div>Home</div>
)

const About = () => (
    <div>About</div>
)

const NavList = () => (
    <ul>
        <ButtonGroup
            variant="contained"
            color="primary"
            size="large"
            aria-label="large contained secondary button group"
        >
            <Button variant="outlined" color="primary">
                <Link to="/">首页</Link>
            </Button>
            <Button variant="outlined" color="primary">
                <Link to="/load">程序装载</Link>
            </Button>
            <Button variant="outlined" color="primary">
                <Link to="/about">关于</Link>
            </Button>
        </ButtonGroup>
    </ul>
)

const RouterList = () => (
    <Router>
        <NavList />
        <Route exact path="/" component={Home} />
        <Route path="/load" component={Load} />
        <Route path="/about" component={About} />
    </Router>
)

export { RouterList }