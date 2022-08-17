#include <iostream>
#include <sstream>

/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

using namespace std;


template<typename E>
// 相当于 动态数组 vector
class ArrayList {
private:
    E* data;
    int capacity;
    int size;

    void resize(int newCapacity) {
        // 1. 创建一个容量为 newCapacity 的临时数组
        E* newData = new E[newCapacity];

        // 2. 将原来数组中的元素拷贝到新数组中
        for (int i = 0; i < this->size; ++i) {
            newData[i] = this->data[i];
        }
        // 3. 将新数组覆盖老数组
        this->data = newData;
        // bug 修复：将容量设置位新容量值
        this->capacity = newCapacity;
    }

public:
    ArrayList() : ArrayList(15) {}

    ArrayList(int capacity) {
        this->data = new E[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    ArrayList(E* arr, int length) {
        this->data = new E[length];
        for (int i = 0; i < length; ++i) {
            this->data[i] = arr[i];
        }
        this->size = length;
        this->capacity = length;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    /**** 新增操作 ****/
    /**
     * 向指定索引位置添加一个新元素
     * @param index 指定索引
     * @param e 新元素
     */
    void add(int index, E e) {
        if (index < 0 || index > size) {
            throw "add failed, require index >= 0 && index <= size";
        }

        // 扩容
        if (size == getCapacity()) {
            resize(getCapacity() * 2);
        }

        // 最差时间复杂度，循环代码运行最大的次数
        // size = data.length && index = 0
        // 时间复杂度 O(n)
        for (int i = size - 1; i >= index; --i) {
            data[i + 1] = data[i];
        }
        data[index] = e;
        size++;
    }

    // 时间复杂度 O(n)
    void addFirst(E e) {
        add(0, e);
    }

    // 时间复杂度 O(1)
    void addLast(E e) {
        add(size, e);
    }

    /**** 查询操作 ****/
    /**
     * 获取 index 索引位置的元素
     * @param index 指定索引
     * @return  返回指定索引对应的元素值
     */
    // 时间复杂度 O(1)
    E get(int index) {
        if (index < 0 || index >= size) {
            throw "get failed, require index >= 0 && index <= size";
        }
        return data[index];
    }

    E getLast() {
        return get(size - 1);
    }

    E getFirst() {
        return get(0);
    }

    // 时间复杂度 O(n)
    bool contains(E target) {
        for (int i = 0; i < size; i++) {
            // TODO：这里有 bug，不是所有类型的数据都有 == 这个操作的
            // 实际上除了 int 等基本类型外，其他类型都不支持 ==
            if (target == data[i]) return true;
        }
        return false;
    }

    /**
     * 查找数组元素 e 所在的索引，如果不存在的元素 e，则返回 -1
     * @param e 指定元素
     * @return  元素 e 所在的索引
     */
    // 时间复杂度 O(n)
    int find(E e) {
        for (int i = 0; i < size; i++) {
            // TODO：这里有 bug，不是所有类型的数据都有 == 这个操作的
            // 实际上除了 int 等基本类型外，其他类型都不支持 ==
            if (data[i] == e) {
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
    void set(int index, E e) {
        if (index < 0 || index >= size) {
            throw "set failed, require index >= 0 && index < size";
        }
        data[index] = e;
    }

    /**** 删除操作 ****/
    /**
     *  删除指定索引位置的元素
     * @param index 指定索引
     * @return  返回删除的元素
     */
    E remove(int index) {
        if (index < 0 || index >= size) {
            throw "remove failed, require index >= 0 && index < size";
        }
        E res = data[index];
        // index = 0 && size = data.length
        // 时间复杂度 O(n)
        for (int i = index + 1; i < size; i++) {
            data[i - 1] = data[i];
        }
        size--;

        // bug 修复：为了避免时间复杂度震荡，我们在 size == getCapacity() / 4 的时候进行缩容
        // // 因为 getCapacity() 有可能不断的减少，所以有可能小于 2 了，所以需要判断下
        if (size == getCapacity() / 4 && getCapacity() / 2 != 0) {
            resize(getCapacity() / 2);
        }
        return res;
    }

    /**
     * 删除第一个元素
     * @return  第一个元素值
     */
    // 时间复杂度 O(n)
    E removeFirst() {
        return remove(0);
    }

    /**
     * 删除最后一个元素
     * @return  最后一个元素的值
     */
    // 时间复杂度 O(1)
    E removeLast() {
        return remove(size - 1);
    }

    /**
     *  删除指定元素
     * @param e 需要删除的元素
     */
    // 时间复杂度 O(n)
    void removeElement(E e) {
        int index = find(e);
        if (index != -1) {
            remove(index);
        }
    }

    string toString() {
        stringstream fmt;
        fmt << "Array: size = " << size << ", capacity = " << getCapacity() << "\n";
        fmt << "[";
        for (int i = 0; i < size; i++) {
            fmt << data[i];
            if (i != size - 1) {
                fmt << ",";
            }
        }
        fmt << "]";
        return fmt.str();
    }
};

int main() {

    ArrayList<string> arrayList;
    arrayList.addFirst("12");
    arrayList.addLast("0");
    arrayList.add(1, "190");

    cout << arrayList.toString() << endl;

    arrayList.remove(0);
    cout << arrayList.toString() << endl;

    return 0;
}