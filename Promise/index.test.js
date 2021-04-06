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
			console.log(res);
			return res;
		},
		(err) => {
			console.log(err);
		}
	)
	.then(
		(res) => {
			console.log(res + 1);
			throw new Error("执行器错误");
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
