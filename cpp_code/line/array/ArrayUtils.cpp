/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>

using namespace std;

/**
 * 判断数组是否为空
 * @param arr
 * @param length c++ 中静态数组中没有提供 length 的属性，所以需要显示的给出数组的长度
 * @return
 */
bool isEmpty(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        // 这里假设等于 0 表示没有元素
        // 这个是不严谨的，因为元素的值就可能是 0
        if (arr[i] != 0) return false;
    }
    return true;
}

int getSize(int *arr, int length) {
    int size = 0;
    for (int i = 0; i < length; ++i) {
        // 这里假设等于 0 表示没有元素
        // 这个是不严谨的，因为元素的值就可能是 0
        if (arr[i] != 0) size++;
    }
    return size;
}

bool contains(int *arr, int length, int target) {
    for (int i = 0; i < length; ++i) {
        if (arr[i] == target) return true;
    }
    return false;
}

/**
 *  将指定的元素插入到指定数组的指定位置上
 * @param src 需要插入元素的数组
 * @param length 需要插入元素的数组的长度
 * @param index 插入数组的位置
 * @param element 需要插入的元素值
 * @return 包含了插入元素的数组
 */
int *insertElement(int *src, int length, int index, int element) {
    int *dest = new int[length + 1];

    for (int i = 0; i < index; ++i) {
        dest[i] = src[i];
    }

    dest[index] = element;

    for (int i = index; i < length; ++i) {
        dest[i + 1] = src[i];
    }

    return dest;
}

/**
 *  从数组中删除指定位置的元素
 * @param src 数组
 * @param length 数组的长度
 * @param index 指定的位置
 * @return 删除元素之后的数组
 */
int *removeElement(int *src, int length, int index) {
    int *dest = new int[length - 1];

    for (int i = 0; i < index; ++i) {
        dest[i] = src[i];
    }

    for (int i = index; i < length - 1; ++i) {
        dest[i] = src[i + 1];
    }
    return dest;
}

int main() {
    int arr[] = {1, 3, 4, 5};
    cout << isEmpty(arr, 4) << endl;
    cout << getSize(arr, 4) << endl;
    cout << contains(arr, 4, 4) << endl;
    cout << "测试插入数据：" << endl;
    int* res = insertElement(arr, 4, 2, 100);
    for (int i = 0; i < 5; ++i) {
        cout << res[i] << endl;
    }

    cout << "测试删除数据：" << endl;
    res = removeElement(arr, 4, 2);
    for (int i = 0; i < 3; ++i) {
        cout << res[i] << endl;
    }

    return 0;
}