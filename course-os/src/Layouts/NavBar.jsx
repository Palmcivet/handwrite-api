import React from 'react';
import PropTypes from 'prop-types';
import Tab from '@material-ui/core/Tab';
import Box from '@material-ui/core/Box';
import Tabs from '@material-ui/core/Tabs';
import AppBar from '@material-ui/core/AppBar';
import { makeStyles } from '@material-ui/core/styles';
import Typography from '@material-ui/core/Typography';
import { HomeApp } from '../Pages/Home';
import { AboutApp } from '../Pages/About';
import { DocApp } from '../Pages/Doc';
import { SideBar } from "./SideBar";

const TabPanel = (props) => {
    const { children, value, index, ...other } = props;

    return (
        <Typography
            component="div"
            role="tabpanel"
            hidden={value !== index}
            id={`simple-tabpanel-${index}`}
            aria-labelledby={`simple-tab-${index}`}
            {...other}
        >
            <Box p={3}>{children}</Box>
        </Typography>
    );
};

TabPanel.propTypes = {
    children: PropTypes.node,
    index: PropTypes.any.isRequired,
    value: PropTypes.any.isRequired,
};

const a11yProps = (index) => {
    return {
        id: `simple-tab-${index}`,
        'aria-controls': `simple-tabpanel-${index}`,
    };
};

const useStyles = makeStyles(theme => ({
    root: {
        flexGrow: 1,
        backgroundColor: theme.palette.background.paper,
    },
}));

const NavBar = () => {
    const classes = useStyles();
    const [value, setValue] = React.useState(0);

    const handleChange = (event, newValue) => {
        setValue(newValue);
    };

    return (
        <div className={classes.root}>
            <AppBar position="static">
                <Tabs value={value} onChange={handleChange} aria-label="simple tabs example">
                    {/* shift */}
                    <Tab label="App" {...a11yProps(1)} />
                    <Tab label="Home" {...a11yProps(0)} />
                    <Tab label="Document" {...a11yProps(2)} />
                    <Tab label="About" {...a11yProps(3)} />
                </Tabs>
            </AppBar>

            {/* Add Tab */}
            <TabPanel value={value} index={0}>
                <SideBar />
            </TabPanel>
            <TabPanel value={value} index={1}>
                <HomeApp />
            </TabPanel>
            <TabPanel value={value} index={2}>
                <DocApp />
            </TabPanel>
            <TabPanel value={value} index={3}>
                <AboutApp />
            </TabPanel>
        </div>
    );
};

export { NavBar };