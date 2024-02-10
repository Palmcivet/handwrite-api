import React from 'react';
import './Paper.less';

const Paper = (props) => {
    return (
        <div className="paper-root">
            <div className="paper-grid" {...props}>
            </div>
        </div>
    );
};

export { Paper };