import React from 'react';
import PropTypes from 'prop-types';
import Tabs from '@material-ui/core/Tabs';
import Tab from '@material-ui/core/Tab';
import Box from '@material-ui/core/Box';
import { LoadApp } from '../Pages/Load';
import { makeStyles } from '@material-ui/core/styles';
import Typography from '@material-ui/core/Typography';

const TabPanel = (props) => {
    const { children, value, index, ...other } = props;

    return (
        <Typography
            component="div"
            role="tabpanel"
            hidden={value !== index}
            id={`vertical-tabpanel-${index}`}
            aria-labelledby={`vertical-tab-${index}`}
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
        id: `vertical-tab-${index}`,
        'aria-controls': `vertical-tabpanel-${index}`,
    };
};

const useStyles = makeStyles(theme => ({
    root: {
        flexGrow: 1,
        backgroundColor: theme.palette.background.paper,
        display: 'flex',
        height: '100%',
    },
    tabs: {
        borderRight: `1px solid ${theme.palette.divider}`,
        minWidth: '160px'
    },
}));

const SideBar = () => {
    const classes = useStyles();
    const [value, setValue] = React.useState(0);

    const handleChange = (event, newValue) => {
        setValue(newValue);
    };

    return (
        <div className={classes.root}>
            <Tabs
                orientation="vertical"
                variant="scrollable"
                value={value}
                onChange={handleChange}
                aria-label="Vertical tabs example"
                className={classes.tabs}
            >
                <Tab label="进程调度" {...a11yProps(0)} />
                <Tab label="死锁" {...a11yProps(1)} />
                <Tab label="程序装入" {...a11yProps(2)} />
                <Tab label="内存分配" {...a11yProps(3)} />
                <Tab label="存储管理" {...a11yProps(4)} />
                <Tab label="更多" {...a11yProps(5)} />
            </Tabs>

            <TabPanel value={value} index={0}>
                Item Two
            </TabPanel>
            <TabPanel value={value} index={1}>
                Item Three
            </TabPanel>
            <TabPanel value={value} index={2}>
                <LoadApp />
            </TabPanel>
            <TabPanel value={value} index={3}>
                Item Four
            </TabPanel>
            <TabPanel value={value} index={4}>
                Item Five
            </TabPanel>
            <TabPanel value={value} index={5}>
                Item Six
            </TabPanel>
        </div>
    );
};

export { SideBar };