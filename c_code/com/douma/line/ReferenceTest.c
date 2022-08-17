/**
* @官方网站 : https://douma.ke.qq.com
* @微信公众号 : 抖码课堂
* @官方微信号 : bigdatatang01
* @作者 : 老汤
*/

#include <stdio.h>

struct home {
    const char *address;
};

struct person {
    const char *name;
    int age;
    struct home h;
};

int main() {
    struct home h;
    h.address = "杭州";

    struct person p;
    p.name = "jeffy";
    p.age = 12;
    p.h = h;

    printf("姓名：%s；年龄：%d；家庭住址：%s", p.name, p.age, p.h.address);

    return 0;
}

