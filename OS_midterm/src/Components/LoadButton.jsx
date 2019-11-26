import React, { Component } from 'react'
import Grid from '@material-ui/core/Grid'
import Button from '@material-ui/core/Button'
import ButtonGroup from '@material-ui/core/ButtonGroup'

class LoadButton extends Component {
    constructor(props) {
        super(props)
        this.state = {
            method: 'absolute'
        }
        this.onChange = this.onChange.bind(this)
    }

    onChange(e) {
        this.setState({
            method: e.target.value
        })
        console.log('checked:', e.target.value);
    }

    render() {
        return (
            <Grid item>
                <ButtonGroup style={{ marginTop: 26 }}
                    onClick={this.onChange}
                    defaultValue="absolute"
                    variant="outlined"
                    color="primary"
                    size="large"
                    aria-label="large contained secondary button group"
                >
                    <Button value="absolute">绝对装入</Button>
                    <Button value="reload">可重定位装入</Button>
                    <Button value="dynamic">动态装入</Button>
                </ButtonGroup>
            </Grid>
        )
    }
}

export { LoadButton }