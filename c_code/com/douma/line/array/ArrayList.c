/**
 * @官方网站 : https://douma.ke.qq.com
 * @微信公众号 : 抖码课堂
 * @官方微信号 : bigdatatang01
 * @作者 : 老汤
 */

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

void init_array_list(struct array_list *list, int capacity, int init_num) {
    int *data = (int *)malloc(capacity * sizeof(int));
    if (data != NULL) {
        list->data = data;
        for (int i = 0; i < capacity; ++i) {
            list->data[i] = init_num;
        }
        list->capacity = capacity;
        list->size = 0;
    }
}

void destroy_array_list(struct array_list *list) {
    if (list->data != NULL) {
        free(list->data);
    }
}

bool is_empty(struct array_list *list) {
    return list->size == 0;
}

size_t get_size(struct array_list *list) {
    return list->size;
}

size_t get_capacity(struct array_list *list) {
    return list->capacity;
}

static void resize(struct array_list *list, int newCapacity) {
    // 1. 创建一个容量为 newCapacity 的临时数组
    int *newData = (int *)malloc(newCapacity * sizeof(int));

    // 2. 将原来数组中的元素拷贝到新数组中
    for (int i = 0; i < list->size; i++) {
        newData[i] = list->data[i];
    }
    for (int i = list->size; i < newCapacity; ++i) {
        newData[i] = 0;
    }
    destroy_array_list(list);

    // 3. 将新数组覆盖老数组
    list->data = newData;
    // bug 修复：将容量设置位新容量值
    list->capacity = newCapacity;
}

/**** 新增操作 ****/
/**
 * C(Create)-R(Retrieve)-U(Update)-D(Delete)
 * 向指定索引位置添加一个新元素
 * @param index 指定索引
 * @param e 新元素
 */
int add(struct array_list *list, int index, int e) {
    if (index < 0 || index > list->size) {
        printf("add failed, require index >= 0 && index <= size\n");
        return 0;
    }
    // 扩容
    if (list->size == list->capacity) {
        resize(list, list->capacity * 2);
    }

    // 最差时间复杂度，循环代码运行最大的次数
    // size = data.length && index = 0
    // 时间复杂度 O(n)
    for (int i = list->size - 1; i >= index; --i) {
        list->data[i + 1] = list->data[i];
    }
    list->data[index] = e;
    list->size++;
    return 1;
}

// 时间复杂度 O(n)
void add_first(struct array_list *list, int e) {
    add(list, 0, e);
}

// 时间复杂度 O(1)
void add_last(struct array_list *list, int e) {
    add(list, list->size, e);
}

/**** 查询操作 ****/
/**
 * 获取 index 索引位置的元素
 * @param index 指定索引
 * @param list 动态链表
 * @return  返回指定索引对应的元素值
 */
// 时间复杂度 O(1)
int get(struct array_list *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("get failed, require index >= 0 && index < size\n");
        exit(-1);
    }
    return list->data[index];
}

int get_last(struct array_list *list) {
    return get(list, list->size - 1);
}

int get_first(struct array_list *list) {
    return get(list, 0);
}

bool contains(struct array_list *list, int target){
    for (int i = 0; i < list->size; ++i) {
        if (list->data[i] == target) {
            return true;
        }
    }
    return false;
}

/**
 * 查找数组元素 e 所在的索引，如果不存在的元素 e，则返回 -1
 * @param e 指定元素
 * @return  元素 e 所在的索引
 */
// 时间复杂度 O(n)
int find(struct array_list *list, int e) {
    for (int i = 0; i < list->size; ++i) {
        if (list->data[i] == e) {
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
void set(struct array_list *list, int index, int e) {
    if (index < 0 || index >= list->size) {
        printf("set failed, require index >= 0 && index < size\n");
        exit(-1);
    }
    list->data[index] = e;
}

/**** 删除操作 ****/
/**
 *  删除指定索引位置的元素
 * @param index 指定索引
 * @return  返回删除的元素
 */
int remove_ele_by_index(struct array_list *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("remove_ele_by_index failed, require index >= 0 && index < size\n");
        exit(-1);
    }

    int res = list->data[index];
    // index = 0 && size = data.length
    // 时间复杂度 O(n)
    for (int i = index + 1; i < list->size; i++) {
        list->data[i - 1] = list->data[i];
    }
    list->size--;

    // bug 修复：为了避免时间复杂度震荡，我们在 size == data.length / 4 的时候进行缩容
    // // 因为 data.length 有可能不断的减少，所以有可能小于 2 了，所以需要判断下
    if (list->size == list->capacity / 4 && list->capacity / 2 != 0) {
        resize(list, list->capacity / 2);
    }
    return res;
}

/**
 * 删除第一个元素
 * @return  第一个元素值
 */
// 时间复杂度 O(n)
int remove_first(struct array_list *list) {
    return remove_ele_by_index(list, 0);
}

/**
 * 删除最后一个元素
 * @return  最后一个元素的值
 */
// 时间复杂度 O(1)
int remove_last(struct array_list *list) {
    return remove_ele_by_index(list, list->size - 1);
}

/**
 *  删除指定元素
 * @param e 需要删除的元素
 */
// 时间复杂度 O(n)
void remove_ele(struct array_list *list, int e) {
    int index = find(list, e);
    if (index != -1) {
        remove_ele_by_index(list, index);
    }
}
