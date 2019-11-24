import React from 'react'

/**
 * @param {Array} code - 2d Array
 */
const Memory = (code) => {
    console.log(code);
    <ul>
        {code.forEach((data) => (
            data.forEach((ins, index) => (
                <li id={index}>
                    {ins}
                </li>
            ))
        ))}
    </ul>
}

export { Memory }