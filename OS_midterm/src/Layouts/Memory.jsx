import React from 'react'
import '../Styles/memory.less'

let id = 0;
/**
 * @param {Array} array - 2d Array
 */
const Memory = (array) => {
    const code = array.props;
    const Li = code.map((data) => (
        data.map((ins) => (
            <li key={id++} className="memory-grid">
                {ins}
            </li>
        ))
    ))

    return (
        <ul>{Li}</ul>
    )
}

export { Memory }