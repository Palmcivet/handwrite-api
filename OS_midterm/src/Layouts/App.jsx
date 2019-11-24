import React from 'react'
import { Program } from '../data'
import { Memory } from './Memory'

let proc = Program("static")

const App = () => (
    <Memory props={proc} />
)

export { App }