/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/
#ifndef CPP_CODE_SET_H
#define CPP_CODE_SET_H

#include <string>

using namespace std;

template <typename E>
class Set {
public:
    virtual int size() = 0;

    virtual bool isEmpty() = 0;

    virtual void add(E&& e) = 0;

    virtual void remove(E&& e) = 0;

    virtual bool contains(E&& e) = 0;

    virtual string toString() = 0;
};

static int intHash(const int &a) {
    return a;
}

static bool intEqual(const int &a, const int &b) {
    return a == b;
}

#endif //CPP_CODE_SET_H
