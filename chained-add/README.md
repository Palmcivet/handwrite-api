# Chained Add

实现一个 `add()` 函数，满足以下用例：

```js
console.log(add(1)(2)(3)(4)(5));
console.log(add(1, 2)(3, 4)(5));
console.log(add(1, 2, 3, 4) + 5);
```

## 思路

使用函数柯里化
