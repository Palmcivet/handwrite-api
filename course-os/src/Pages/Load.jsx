import React, { Component } from 'react';
import Grid from '@material-ui/core/Grid';
import TextField from '@material-ui/core/TextField';
import Chip from '@material-ui/core/Chip';
import { METHOD, METHOD_CN, addrFix } from "../Config/config";
import { LoadData } from "../Data/LoadData";
import { Memory } from '../Components/Memory';
import { Paper } from '../Components/Paper';
import { Btn } from '../Components/Button';

let offset = parseInt(Math.floor(Math.random() * 10000), 16);

class LoadApp extends Component {
    constructor(props) {
        super(props);
        this.state = {
            type: METHOD[0],
            base_run: offset,
            base_code: offset,
            base_input: '',
            code: LoadData(offset),
        };
    }

    render() {
        return (
            <div>
                <Grid container spacing={5}>
                    <Grid item xs={7}>
                        <Paper>
                            <Memory>
                                {this.state.code}
                            </Memory>
                        </Paper>
                    </Grid>
                    <Grid item xs={4}>
                        <Paper>
                            <Chip
                                label={"代码基地址：" + addrFix(this.state.base_code)}
                                color="primary"
                                variant="outlined"
                            />
                            <Chip
                                label={"进程基地址：" + addrFix(this.state.base_run)}
                                color="primary"
                                variant="outlined"
                            />
                            <Chip
                                label={"当前使用：" + METHOD_CN[this.state.type]}
                                color="primary"
                                variant="outlined"
                            />
                        </Paper>
                        <Paper>
                            <Btn
                                onClick={
                                    (e) => (this.setState({
                                        type: 'absolute',
                                        code: LoadData(this.state.base_code),
                                        base_run: this.state.base_code,
                                    }))}
                            >
                                绝对装载
							</Btn>
                            <Btn
                                onClick={
                                    (e) => (this.setState({
                                        type: 'reload',
                                        code: LoadData(parseInt(this.state.base_input, 16) || this.state.base_code),
                                        base_run: parseInt(this.state.base_input, 16) || this.state.base_code,
                                    }))}
                            >
                                可重定位装载
							</Btn>
                            <TextField id="standard-basic" label="基地址"
                                value={this.state.base_input}
                                onChange={(e) => (
                                    this.setState(Object.assign({}, this.state, { base_input: e.target.value }))
                                )}
                                style={{ outline: 'none' }}
                            />
                        </Paper>
                    </Grid>
                </Grid>
            </div >
        );
    }
}

export { LoadApp };