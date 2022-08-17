/**
 * @官方网站 : https://douma.ke.qq.com
 * @微信公众号 : 抖码课堂
 * @官方微信号 : bigdatatang01
 * @作者 : 老汤
 */

#include <stdio.h>
#include "ArrayList.h"


int main() {
    struct array_list *list;
    init_array_list(list, 10, 0);
    printf("%d\n", is_empty(list));

    add_first(list, 34);
    add_last(list, 23);
    add(list, 2, 50);
    printf("%d\n", is_empty(list));

    for (int i = 0; i < list->capacity; ++i) {
        printf("%d, ", list->data[i]);
    }

    printf("\n");

    remove_ele_by_index(list, 1);
    remove_ele(list, 1);

    for (int i = 0; i < list->capacity; ++i) {
        printf("%d, ", list->data[i]);
    }

    // 释放内存
    destroy_array_list(list);
    return 0;
}
