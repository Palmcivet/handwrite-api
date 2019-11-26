import React from 'react'
import PropTypes from 'prop-types'
import { makeStyles } from '@material-ui/core/styles'
import AppBar from '@material-ui/core/AppBar'
import Tabs from '@material-ui/core/Tabs'
import Tab from '@material-ui/core/Tab'
import Typography from '@material-ui/core/Typography'
import Box from '@material-ui/core/Box'
import { Link, BrowserRouter as Router } from 'react-router-dom'
import { RouterList } from './Router'

const Home = () => (
    <div>Home</div>
)

const About = () => (
    <div>About</div>
)

const NavList = () => (
    <Router>
        <ul>
            <Link to="/">首页</Link>
            <Link to="/load">程序装载</Link>
            <Link to="/about">关于</Link>
        </ul>
    </Router>
)

const TabPanel = (props) => {
    const { children, value, index, ...other } = props;

    return (
        <Typography
            component="div"
            role="tabpanel"
            hidden={value !== index}
            id={`nav-tabpanel-${index}`}
            aria-labelledby={`nav-tab-${index}`}
            {...other}
        >
            <Box p={3}>{children}</Box>
        </Typography>
    );
}

TabPanel.propTypes = {
    children: PropTypes.node,
    index: PropTypes.any.isRequired,
    value: PropTypes.any.isRequired,
};

function a11yProps(index) {
    return {
        id: `nav-tab-${index}`,
        'aria-controls': `nav-tabpanel-${index}`,
    };
}

function LinkTab(props) {
    return (
        <Tab
            component="a"
            onClick={event => {
                event.preventDefault();
            }}
            {...props}
        />
    );
}

const useStyles = makeStyles(theme => ({
    root: {
        flexGrow: 1,
        backgroundColor: theme.palette.background.paper,
    }
}))

const NavBar = () => {
    const classes = useStyles();
    const [value, setValue] = React.useState(0);

    const handleChange = (newValue) => {
        setValue(newValue)
    }

    return (
        <div className={classes.root}>
            <AppBar position="static">
                <Tabs
                    variant="fullWidth"
                    value={value}
                    onChange={handleChange}
                    aria-label="nav tabs example"
                >
                    <LinkTab label="home" href="/" {...a11yProps(0)} />
                    <LinkTab label="load" href="/load" {...a11yProps(0)} />
                    <LinkTab label="about" href="/about" {...a11yProps(1)} />
                </Tabs>
            </AppBar>
            <TabPanel value={value} index={0}>
                Page One
      </TabPanel>
            <TabPanel value={value} index={1}>
                Page Two
      </TabPanel>
            <TabPanel value={value} index={2}>
                Page Three
      </TabPanel>
        </div>
    )
}
export { NavList }
// export { NavBar }