/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <stack>
#include <iostream>
#include <sstream>

#include "./BST.cpp"
#include "./BSTR.cpp"

using namespace std;

static int intCompare(int x, int y) {
    return x - y;
}

int main() {
    // BST<int, decltype(&intCompare)> bst(intCompare);
    BSTR<int, decltype(&intCompare)> bst(intCompare);
    bst.add(33);
    bst.add(22);
    bst.add(66);
    bst.add(12);
    bst.add(35);
    bst.add(70);
    bst.add(34);
    bst.add(50);
    bst.add(68);
    bst.add(99);

    vector<int> res = bst.inOrder();
    stringstream fmt;
    for (int i = 0; i < res.size(); ++i) {
        fmt << to_string(res[i]) << ", ";
    }
    cout << fmt.str() << endl;

    cout << to_string(bst.contains(34)) << endl;

    cout << to_string(bst.minValue()) << endl;
    cout << to_string(bst.maxValue()) << endl;

    cout << to_string(bst.removeMin()) << endl;

    res = bst.inOrder();
    stringstream fmt1;
    for (int i = 0; i < res.size(); ++i) {
        fmt1 << to_string(res[i]) << ", ";
    }
    cout << fmt1.str() << endl;


    cout << to_string(bst.removeMax()) << endl;

    res = bst.inOrder();
    stringstream fmt2;
    for (int i = 0; i < res.size(); ++i) {
        fmt2 << to_string(res[i]) << ", ";
    }
    cout << fmt2.str() << endl;


    bst.remove(66);
    res = bst.inOrder();
    stringstream fmt3;
    for (int i = 0; i < res.size(); ++i) {
        fmt3 << to_string(res[i]) << ", ";
    }
    cout << fmt3.str() << endl;

    return 0;
}