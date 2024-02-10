/**
 * JS 数值计算，默认返回十进制, 补前缀 ` 0x`，并 8 位对齐
 * @param {Number} addr - 待变换的地址
 * @param {Number} offset - 偏移地址
 * @returns {String} ` 0x` 形式字符串
 */
const relocate = (addr, offset) => {
    let new_addr = ' 0x';
    new_addr += String((addr + offset).toString(16)).padStart(8, '0');
    return new_addr;
};

/**
 * 修整地址的显示格式
 * @param {Number} addr - 十六进制数值
 * @returns {String} - `0x` 形式字符串
 */
const addrFix = (addr) => {
    let new_addr = '0x';
    new_addr += (addr).toString(16).padStart(8, '0');
    return new_addr;
};

const METHOD = ["absolute", "reload", "dynamic"];
const METHOD_CN = {
    "absolute": "绝对装载",
    "reload": "可重定位装载",
    "dynamic": "动态装载"
};

export { METHOD, METHOD_CN, relocate, addrFix };