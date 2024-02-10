import { relocate, METHOD, METHOD_CN } from '../Config/config';
import { observable, action } from "mobx";

class StoreLoad {
    'use strict';
    constructor() {
        this.getStore = this.getStore.bind(this);
        this.changeBase = this.changeBase.bind(this);
        this.changeMethod = this.changeMethod.bind(this);
        this.changeMethod();
    }

    @observable
    storeState = {
        code: '',           // 二维数组
        stat_id: 0,         // 数据标识符
        stat_type: '',      // 装载的方式
        // 程序的基址
        base_code: parseInt(Math.floor(Math.random() * 65536), 16),
        base_proc: 0x0,     // 进程的基址
        base_input: '',     // 输入的基址
    };

    @action getStore = () => {
        return this.storeState;
    }

    /**
     * 切换示例程序，或初始化
     * @param {Number} base - 基地址
     * @param {Number} id - 可待加载的程序标识符，类型未定
     * @returns {Array} 加载了基地址的二维数组
     */
    changeCode = (base = 0x0, id = 0) => {
        const tmpProc = data[id];
        for (let index in Object.keys(tmpProc.addr)) {
            tmpProc.code[index] += relocate(tmpProc.addr[index], base);
        }
        return tmpProc.code;
    }

    /**
     * @param {Number} base - 根据用户输入的基址实时修改
     */
    changeBase = (base = 0x0) => {
        this.storeState.base_input = base;
    }

    changeMethod = (method = METHOD[0], id = 0) => {
        this.storeState.id = id;
        this.storeState.stat_type = METHOD_CN[method];
        this.storeState.base_proc = this.storeState.base_input || this.storeState.base_code;
        this.storeState.code = this.changeCode(this.storeState.base_proc, id);
    }
}

export { StoreLoad };