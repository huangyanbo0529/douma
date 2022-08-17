/**
 * @官方网站 : https://douma.ke.qq.com
 * @微信公众号 : 抖码课堂
 * @官方微信号 : bigdatatang01
 * @作者 : 老汤
 */

#include <stdbool.h>
#include <stdio.h>

bool is_empty(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        // 这里假设等于 0 表示没有元素
        // 这个是不严谨的，因为元素的值就可能是 0
        if (arr[i] != 0) return false;
    }
    return true;
}

int get_size(int *arr, int len) {
    // c 语言的数组长度必须先告知
    return len;
}

bool contains(int *arr, int len, int target) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] == target) return true;
    }
    return false;
}

/**
 * 将指定的元素插入到指定数组的指定位置上
 * @param src   源数组
 * @param len   数组的长度
 * @param dest  目标数组
 * @param index 插入数组的位置
 * @param element   需要插入的元素值
 */
void insert_element(int *src, int len, int *dest, int index, int element) {

    for (int i = 0; i < index; ++i) {
        dest[i] = src[i];
    }

    dest[index] = element;

    for (int i = index; i < len; ++i) {
        dest[i + 1] = src[i];
    }

}

/**
 * 从数组中删除指定位置的元素
 * @param src   源数组
 * @param len   数组的长度
 * @param dest  目标数组
 * @param index 指定的位置
 */
void remove_element(int *src, int len, int *dest, int index) {

    for (int i = 0; i < index; ++i) {
        dest[i] = src[i];
    }

    for (int i = index; i < len - 1; ++i) {
        dest[i] = src[i + 1];
    }

}

int main() {
    int src[3] = {1, 2, 4};
    int dest[4];

    insert_element(src, 3, dest, 2, 99);
    for (int i = 0; i < 4; ++i) {
        printf("%d，", dest[i]);
    }

    printf("\n");

    int dest2[2];
    remove_element(src, 3, dest2, 2);
    for (int i = 0; i < 2; ++i) {
        printf("%d，", dest2[i]);
    }
    return 0;
}

