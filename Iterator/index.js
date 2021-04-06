/**
 * 实现一个可迭代协议
 */
function IterableCreator(params) {
	// 逻辑代码

	return {
		[Symbol.iterator]: function () {
			return this;
		},
	};
}

/**
 * 实现一个迭代器对象
 */
function IteratorCreator(params) {
	// 逻辑代码

	return {
		next() {},
	};
}

/**
 * 一个普通对象包装为可迭代对象
 * @param {object} obj 对象
 */
function* IterableObject(obj) {
	for (let key of Object.keys(obj)) {
		yield obj[key];
	}
}

module.exports = {
	IterableObject,
};
