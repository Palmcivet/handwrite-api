import React from 'react'
import Grid from '@material-ui/core/Grid'
import Paper from '@material-ui/core/Paper'
import { makeStyles } from '@material-ui/core/styles'
import GridList from '@material-ui/core/GridList'
import GridListTile from '@material-ui/core/GridListTile'
import ListSubheader from '@material-ui/core/ListSubheader'
import { Memory } from '../Components/Memory'
import { LoadButton } from '../Components/LoadButton'
import { Program } from '../data'

const useStyles = makeStyles(theme => ({
    root: {
        flexGrow: 1,
    },
    gridList: {
        width: 500,
        height: "80%",
    },
    paper: {
        padding: theme.spacing(3),
        textAlign: 'center',
        color: theme.palette.text.secondary,
    },
}))

const Load = () => {
    const classes = useStyles()

    return (
        <div className={classes.root}>
            <Grid container spacing={3}>
                <Grid item xs>
                    <GridList cellHeight={"auto"} className={classes.gridList}>
                        <GridListTile key="Subheader" cols={2} style={{ height: 'auto' }}>
                            <ListSubheader component="div">内存示意图</ListSubheader>
                        </GridListTile>
                        <Grid item xs>
                            <Paper className={classes.paper}>
                                <Memory props={Program("absolute")} />
                            </Paper>
                        </Grid>
                    </GridList>
                </Grid>
                <Grid item xs>
                    <Paper className={classes.paper}>
                        <LoadButton />
                    </Paper>
                </Grid>
            </Grid>
        </div>
    );
}

export { Load }