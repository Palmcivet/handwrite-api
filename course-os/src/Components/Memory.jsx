import React from 'react';
import './Memory.less';

let id = 0;
const Memory = (props) => {
    let proc = props['children'];

    const Li = proc.map((arr_1) => (
        arr_1.map((arr_2) => (
            <li key={id++} className="memory-grid">
                {arr_2}
            </li>
        ))
    ));

    return (
        <div className="memory-Box">
            <ul>{Li}</ul>
        </div>
    );
};

export { Memory };