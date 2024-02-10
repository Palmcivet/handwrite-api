"use strict";

function add(...initArgs) {
	var _args = [...initArgs];

	function _add(...arg) {
		_args.push(...arg);
		return _add;
	}

	_add.toString = function () {
		return _args.reduce((a, b) => {
			return a + b;
		});
	};

	return _add;
}

console.log(add(1)(2)(3)(4)(5));
console.log(add(1, 2)(3, 4)(5));
console.log(add(1, 2, 3, 4) + 5);
