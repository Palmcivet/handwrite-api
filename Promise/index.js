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

	resolve(value) {
		if (this.status === PENDING) {
			this.status = FULFILLED;
			this.value = value;
			while (this.onFullfilledQueue.length > 0) {
				try {
					this.value = this.onFullfilledQueue.shift()(this.value);
				} catch (err) {
					this.reject(err);
				}
			}
		}
	}

	reject(error) {
		if (this.status === PENDING) {
			console.log(error);
			this.status = REJECTED;
			this.error = error;
			while (this.onRejectedQueue.length > 0) {
				this.error = this.onRejectedQueue.shift()(this.error);
			}
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
