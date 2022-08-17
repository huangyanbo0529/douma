

class ArrayList {

    constructor() {
        // js 中的数组是天然的动态数组
        this.data = []
    }

    isEmpty() {
        return this.data.length == 0
    }

    getSize() {
        return this.data.length
    }

    /**** 新增操作 ****/
    /**
     * 向指定索引位置添加一个新元素
     * @param index 指定索引
     * @param e 新元素
     */
    add(index, e) {
        if (index < 0 || index > this.data.length) {
            throw new Error("add failed, require index >= 0 && index <= size")
        }

        // 注意：不用扩容，因为 js 的数组是动态数组，底层会自动扩容的

        // 1. 从索引为 index 的元素开始，往后挪一位
        // 最差时间复杂度，循环代码运行最大的次数
        // size = data.length && index = 0
        // 时间复杂度 O(n)
        for (let i = this.getSize() - 1; i >= index; i--) {
            this.data[i + 1] = this.data[i]
        }

        // 2. 在索引为 index 的位置设置 e
        this.data[index] = e
    }

    // 时间复杂度 O(n)
    addFirst(e) {
        this.add(0, e);
    }

    // 时间复杂度 O(1)
    addLast(e) {
        this.add(this.getSize(), e);
    }

    /**** 查询操作 ****/
    /**
     * 获取 index 索引位置的元素
     * @param index 指定索引
     * @return  返回指定索引对应的元素值
     */
    get(index) {
        if (index < 0 || index >= this.data.length) {
            throw new Error("get failed, require index >= 0 && index <= size")
        }
        return this.data[index]
    }

    getLast() {
        return this.get(this.getSize() - 1)
    }

    getFirst() {
        return this.get(0)
    }

    // 时间复杂度 O(n)
    contains(target) {
        for (const num of this.data) {
            if (target == num) return true;
        }
        return false;
    }

    /**
     * 查找数组元素 e 所在的索引，如果不存在的元素 e，则返回 -1
     * @param e 指定元素
     * @return  元素 e 所在的索引
     */
    // 时间复杂度 O(n)
    find(e) {
        for (let i = 0; i < this.getSize(); i++) {
            if (this.data[i] == e) {
                return i;
            }
        }
        return -1;
    }

    /**** 修改操作 ****/
    /**
     *  将 index 索引位置的元素修改为新元素 e
     * @param index 需要修改的索引位置
     * @param e 新设置的元素值
     */
    // 时间复杂度 O(1)
    set(index, e) {
        if (index < 0 || index >= this.data.length) {
            throw new Error("set failed, require index >= 0 && index <= size")
        }
        this.data[index] = e
    }

    /**** 删除操作 ****/

    /**
     *  删除指定索引位置的元素
     * @param index 指定索引
     * @return  返回删除的元素
     */
    remove(index) {
        if (index < 0 || index >= this.data.length) {
            throw new Error("add failed, require index >= 0 && index <= size")
        }

        // 1. 记住需要删除的元素
        const res = this.data[index]

        // 2. 将要删除的元素的后面所有元素往前移动一位
        for (let i = index + 1; i < this.getSize(); i++) {
            this.data[i - 1] = this.data[i]
        }

        // 3. 删掉最后一个元素
        // 注意：不用缩容，因为 js 的数组是动态数组，底层会自动缩容的
        this.data.pop()

        return res
    }

    /**
     * 删除第一个元素
     * @return  返回删除的元素
     */
    // 时间复杂度 O(n)
    removeFirst() {
        return this.remove(0)
    }

    /**
     * 删除最后一个元素
     * @return  返回删除的元素
     */
    // 时间复杂度 O(1)
    removeFirst() {
        return this.remove(this.getSize() - 1)
    }

    /**
     *  删除指定元素
     * @param e 需要删除的元素
     */
    // 时间复杂度 O(n)
    removeElement(e) {
        const index = this.find(e)
        if (index != -1) {
            this.remove(index)
        }
    }

    toString() {
        let res = `Array: size = ${this.getSize()}\n`
        res += "["
        for (let i = 0; i < this.getSize(); i++) {
            res += this.data[i]
            if (i != this.getSize() - 1) {
                res += ","
            }
        }
        res += "]"
        return res
    }
}

const arrayList = new ArrayList()
console.log(arrayList.isEmpty())

arrayList.addFirst(34)
arrayList.addLast(23)
arrayList.add(2, 50)
console.log(arrayList.isEmpty())

console.log(arrayList.toString())


arrayList.remove(1)
console.log(arrayList.toString())

arrayList.removeElement(50)
console.log(arrayList.toString())