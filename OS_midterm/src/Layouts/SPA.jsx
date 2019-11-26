import React from 'react'
import Grid from '@material-ui/core/Grid'
import Paper from '@material-ui/core/Paper'
import { makeStyles } from '@material-ui/core/styles'
import { Memory } from '../Components/Memory'
import { B2T } from '../Components/B2T'
import { NavBar } from './NavBar'
import { Load } from './Load'
import { Program } from '../data'


const useStyles = makeStyles(theme => ({
    root: {
        flexGrow: 1,
    },
    paper: {
        padding: theme.spacing(3),
        textAlign: 'center',
        color: theme.palette.text.secondary,
    },
}))

const MemoryLoad = () => {
    const classes = useStyles()

    return (
        <div className={classes.root}>
            <Grid container spacing={3}>
                <Grid item xs>
                    <Paper className={classes.paper}>
                        <Memory props={Program("absolute")} />
                    </Paper>
                </Grid>
                <Grid item xs>
                    <Paper className={classes.paper}>
                        <Load />
                    </Paper>
                </Grid>
            </Grid>
        </div>
    );
}

const SPA = () => (
    <div>
        <NavBar />
        <MemoryLoad />
        <B2T />
    </div>
)

export { SPA }