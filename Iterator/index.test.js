const { IterableObject } = require("./index");

const obj = {
	a: 2,
	b: "4",
	c: function () {},
	d: false,
};

const res = IterableObject(obj);

for (const item of res) {
	console.log(item);
}
