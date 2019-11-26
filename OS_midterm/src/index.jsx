import React from 'react'
import { render } from 'react-dom'
import { RouterList } from './Router/Router'
import { NavList } from './Router/NavBar'

render(
    <>
        <NavList />
        <RouterList />
    </>,
    document.getElementById('root')
)