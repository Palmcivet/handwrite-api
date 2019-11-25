import React, { Component } from 'react'

class Load extends Component {
    constructor(props) {
        super(props)
        this.handleSwitch = this.handleSwitch.bind(this)
        this.state = {
            method={
                absolute: true,
                reload: false,
                dynamic: false
            }
        }
    }

    handleSwitch(event) {
        this.setState({  })
        console.log(this.state.method)
    }

    render() {
        return (
            <div>
                <label>选择装入方式：</label>
                <br />
                <label>
                    <input type="radio" value="绝对装入" checked={this.state.method.absolute} onChange={this.handleSwitch} />绝对装入
                </label>
                <label>
                    <input type="radio" value="可重定位装入" checked={this.state.method.reload} onChange={this.handleSwitch} />可重定位装入
                </label>
                <label>
                    <input type="radio" value="动态装入" checked={this.state.method.dynamic} onChange={this.handleSwitch} />动态装入
                </label>
            </div>
        )
    }
}

export { Load }