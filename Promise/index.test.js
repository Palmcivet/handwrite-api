"use strict";

const TinyPromise = require("./index");

const promise = new TinyPromise(function (resolve, reject) {
	setTimeout(() => {
		resolve(1);
	}, 500);
});

const p1 = promise
	.then(
		(res) => {
			console.log(res, "first");
			throw new Error("执行器错误");
		},
		(err) => {
			console.log(err);
		}
	)
	.then(
		(res) => {
			console.log(res);
			return 2;
		},
		(err) => {
			console.log(err);
		}
	)
	.catch((err) => {
		console.error(err);
	})
	.catch((err) => {
		console.error(err);
	});

  Promise.resolve().then(() => {
    console.log(0);
    return Promise.resolve(4);
}).then((res) => {
    console.log(res)
})

Promise.resolve().then(() => {
    console.log(1);
}).then(() => {
    console.log(2);
}).then(() => {
    console.log(3);
}).then(() => {
    console.log(5);
}).then(() =>{
    console.log(6);
})
