import React, { Component } from 'react'

class Load extends Component {
    constructor(props) {
        super(props)
        this.handleSwitch = this.handleSwitch.bind(this)
        this.state = {
            method: "absolute"
        }
    }

    handleSwitch(e) {
        this.setState({ method: e.target.value })
    }

    render() {
        return (
            <select value={this.state.value} onChange={(e) => this.handleSwitch(e)}>
                <option value="absolute">绝对装入</option>
                <option value="reload">可重定位装入</option>
                <option value="dynamic">动态装入</option>
            </select>
        )
    }
}

export { Load }