import React from 'react';
import './Button.less';

const Btn = (props) => {
    return (
        <button className="btn-outline">
            <span className="btn-label" {...props}></span>
            <span className="btn-ripple"></span>
        </button>
    )
};

export { Btn };