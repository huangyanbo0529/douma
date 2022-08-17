/**
 * @官方网站 : https://douma.ke.qq.com
 * @微信公众号 : 抖码课堂
 * @官方微信号 : bigdatatang01
 * @作者 : 老汤
 */

#ifndef C_CODE_ARRAYLIST_H
#define C_CODE_ARRAYLIST_H

#include <stdbool.h>

struct array_list {
    int *data;
    int capacity;
    int size;
};

extern void init_array_list(struct array_list *list, int capacity, int init_num);
extern void destroy_array_list(struct array_list *list);

extern bool is_empty(struct array_list *list);
extern size_t get_size(struct array_list *list);
extern size_t get_capacity(struct array_list *list);

/**** 新增操作 ****/
extern int add(struct array_list *list, int index, int e);
extern void add_first(struct array_list *list, int e);
extern void add_last(struct array_list *list, int e);

/**** 查询操作 ****/
extern int get(struct array_list *list, int index);
extern int get_last(struct array_list *list);
extern int get_first(struct array_list *list);
extern bool contains(struct array_list *list, int target);
extern int find(struct array_list *list, int e);

/**** 修改操作 ****/
extern void set(struct array_list *list, int index, int e);

/**** 删除操作 ****/
extern int remove_ele_by_index(struct array_list *list, int index);
extern int remove_first(struct array_list *list);
extern int remove_last(struct array_list *list);
extern void remove_ele(struct array_list *list, int e);


#endif //C_CODE_ARRAYLIST_H
