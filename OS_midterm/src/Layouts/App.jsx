import React from 'react'
import { Program } from '../data'
import { Memory } from './Memory'
import { Load } from './Load'

const App = () => (
    <div>
        <Memory props={Program("absolute")} />
        <Load />
    </div>
)

export { App }