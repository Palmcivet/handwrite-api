import React from 'react'
import './Memory.less'

let id = 0;
/**
 * @param {Array} array - 2d Array
 */
const Memory = (array) => {
    const code = array.props;
    const Li = code.map((data) => (
        data.map((ins) => (
            <li key={id++} className="styleGrid">
                {ins}
            </li>
        ))
    ))

    return (
            <div className="styleBox">
                <ul>{Li}</ul>
            </div>
    )
}

export { Memory }