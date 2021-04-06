const PENDING = "pending";
const FULFILLED = "fulfilled";
const REJECTED = "rejected";

class TinyPromise {
	constructor(executor) {
		try {
			executor(this.resolve.bind(this), this.reject.bind(this));
		} catch (err) {
			this.reject(err);
		}
	}

	status = PENDING;

	value = undefined;

	error = undefined;

	onFullfilledQueue = [];

	onRejectedQueue = [];

	handleReady(queue, val) {
		if (queue.length <= 0) return;

		queueMicrotask(() => {
			try {
				val = queue.shift()(val);
				this.handleReady(queue, val);
			} catch (err) {
				this.reject(err);
			}
		});
	}

	resolve(value) {
		if (this.status === PENDING) {
			this.status = FULFILLED;
			this.value = value;
			this.handleReady(this.onFullfilledQueue, this.value);
		}
	}

	reject(error) {
		if (this.status === PENDING) {
			this.status = REJECTED;
			this.error = error;
			this.handleReady(this.onRejectedQueue, this.error);
		}
	}

	then(onFullfilled, onRejected) {
		if (this.status === FULFILLED) {
			if (onFullfilled) this.value = onFullfilled(this.value);
		} else if (this.status === REJECTED) {
			if (onRejected) this.error = onRejected(this.error);
		} else {
			onFullfilled && this.onFullfilledQueue.push(onFullfilled);
			onRejected && this.onRejectedQueue.push(onRejected);
		}
		return this;
	}

	catch(onError) {
		onError && this.onRejectedQueue.push(onError);
		return this;
	}
}

module.exports = TinyPromise;
