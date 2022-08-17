/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/
#ifndef CPP_CODE_STACK_H
#define CPP_CODE_STACK_H

#include <string>

template <typename E>
class Stack {
    /**
     * 查看栈中元素个数
     * @return
     */
    virtual int getSize() = 0;

    /**
     * 判断栈是否为空
     * @return
     */
    virtual bool isEmpty() = 0;

    /**
     * 进栈
     * 将元素 e 压入栈中
     * @param e
     */
    virtual void push(E e) = 0;

    /**
     * 出栈
     * 将栈顶的元素出栈
     * @return
     */
    virtual E pop() = 0;

    /**
     * 查询栈顶的元素
     * @return
     */
    virtual E peek() = 0;

    virtual std::string toString() = 0;
};

#endif //CPP_CODE_STACK_H
