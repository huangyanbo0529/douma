/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#ifndef CPP_CODE_QUEUE_H
#define CPP_CODE_QUEUE_H

#include <string>

template <typename E>
class Queue {
    /**
     * 查询队列中的元素个数
     * @return
     */
    virtual int getSize() = 0;

    /**
     * 判断队列是否为空
     * @return
     */
    virtual bool isEmpty() = 0;

    /**
     * 入队
     * @param e
     */
    virtual void enqueue(E e) = 0;

    /**
     * 出队
     * @return
     */
    virtual E dequeue() = 0;

    /**
     * 查看队首的元素
     * @return
     */
    virtual E getFront() = 0;

    virtual std::string toString() = 0;
};

#endif //CPP_CODE_QUEUE_H
