/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/
#include <iostream>

#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
    /*
     * C++ 中提供了两种常用的 Set：
     *  1. 基于哈希函数实现的 Set，即 unordered_set 需要 #include <unordered_set>
     *  2. 基于红黑树实现的 Set(有序)， 即 set，需要 #include <set>
     *  他们的方法是一样的
     */
    cout << "...............1. 基于哈希函数实现的 Set，即 unordered_set....................." << endl;
    // 基于哈希函数实现的 Set，即 HashSet
    unordered_set<int> set1;
    set1.insert(10);
    set1.insert(10);
    set1.insert(10);

    // set 只会有一个数据，那就是 10
    // 遍历 Set 的方式一：
    for (unordered_set<int>::iterator iter = set1.begin(); iter != set1.end(); ++iter) {
        cout << to_string(*iter) << endl;
    }
    // 遍历 Set 的方式二：
    for (auto& v : set1) {
        cout << to_string(v) << endl;
    }

    cout << "...................................." << endl;

    set1.insert(20);
    set1.insert(30);

    // 删除 10
    set1.erase(10);
    // set 会有两个数据，分别是 20 和 30
    for (unordered_set<int>::iterator iter = set1.begin(); iter != set1.end(); ++iter) {
        cout << to_string(*iter) << endl;
    }

    // 判断 set 中是否存在某个元素的两种方式
    if (set1.count(20)) {
        cout << "set 中包含了 20" << endl;
    }
    if (set1.find(20) != set1.end()) {
        cout << "set 中包含了 20" << endl;
    }

    cout << "...............2. 基于红黑树实现的 Set， 即 set....................." << endl;

    set<int> set2;
    set2.insert(10);
    set2.insert(10);
    set2.insert(10);

    // set 只会有一个数据，那就是 10
    // 遍历 Set 的方式一：
    for (set<int>::iterator iter = set2.begin(); iter != set2.end(); ++iter) {
        cout << to_string(*iter) << endl;
    }
    // 遍历 Set 的方式二：
    for (auto& v : set2) {
        cout << to_string(v) << endl;
    }

    cout << "...................................." << endl;

    set2.insert(20);
    set2.insert(30);

    // 删除 10
    set2.erase(10);
    // set 会有两个数据，分别是 20 和 30
    for (set<int>::iterator iter = set2.begin(); iter != set2.end(); ++iter) {
        cout << to_string(*iter) << endl;
    }

    // 判断 set 中是否存在某个元素的两种方式
    if (set2.count(20)) {
        cout << "set 中包含了 20" << endl;
    }
    if (set2.find(20) != set2.end()) {
        cout << "set 中包含了 20" << endl;
    }


    /*
     * C++ 中提供了两种常用的 Map：
     *  1. 基于哈希函数实现的 Map，即 unordered_map 需要 #include <unordered_map>
     *  2. 基于红黑树实现的 Map(有序)， 即 map，需要 #include <map>
     *  他们的方法是一样的
     */
    cout << "...............1. 基于哈希函数实现的 Map，即 unordered_map....................." << endl;
    // 基于哈希函数实现的 Map，即 HashMap

    unordered_map<int, int> map1;

    // 添加 key-value 键值对
    map1[10] = 20;
    // 修改 key 对应的 value 值
    map1[10] = 30;

    // 遍历 Map 的方式一：
    for(unordered_map<int ,int>::iterator iter = map1.begin();iter != map1.end(); iter++) {
        cout<<"key value is：" << iter->first << " the mapped value is：" << iter->second << endl;
    }

    // 遍历 Map 的方式二：
    for(auto& kv : map1) {
        cout<<"key value is：" << kv.first << " the mapped value is：" << kv.second << endl;
    }

    map1[20] = 30;
    map1[30] = 10;

    // 删除 key-value 键值对
    map1.erase(10);

    // 遍历 Map 的方式二：
    for(auto& kv : map1) {
        cout<<"key value is：" << kv.first << " the mapped value is：" << kv.second << endl;
    }

    // 判断 Map 中是否存在某个 key 的两种方式
    if (map1.count(20)) {
        cout << "set 中包含了 20" << endl;
    }
    if (map1.find(20) != map1.end()) {
        cout << "set 中包含了 20" << endl;
    }

    cout << "...............2. 基于红黑树实现的 Map(有序)， 即 map，需要 #include <map>....................." << endl;
    // 基于哈希函数实现的 Map，即 HashMap

    map<int, int> map2;

    // 添加 key-value 键值对
    map2[10] = 20;
    // 修改 key 对应的 value 值
    map2[10] = 30;

    // 遍历 Map 的方式一：
    for(map<int ,int>::iterator iter = map2.begin();iter != map2.end(); iter++) {
        cout<<"key value is：" << iter->first << " the mapped value is：" << iter->second << endl;
    }

    // 遍历 Map 的方式二：
    for(auto& kv : map2) {
        cout<<"key value is：" << kv.first << " the mapped value is：" << kv.second << endl;
    }

    map2[20] = 30;
    map2[30] = 10;

    // 删除 key-value 键值对
    map2.erase(10);

    // 遍历 Map 的方式二：
    for(auto& kv : map2) {
        cout<<"key value is：" << kv.first << " the mapped value is：" << kv.second << endl;
    }

    // 判断 Map 中是否存在某个 key 的两种方式
    if (map2.count(20)) {
        cout << "set 中包含了 20" << endl;
    }
    if (map2.find(20) != map2.end()) {
        cout << "set 中包含了 20" << endl;
    }

    return 0;
}