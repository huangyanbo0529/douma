package com.douma.line.queue.practice;

import java.util.Stack;

/**
 * @微信公众号 : 抖码课堂
 * @官方微信号 : bigdatatang01
 * @作者 : 老汤
 */
public class _jianzhi_9_ {
    /*
        请用两个栈来实现一个队列，这个队列的实现类中含有两个方法：
        1. appendTail(int value) ：在队列的尾部插入一个整数
        2. deleteHead() ：删除队列头部的元素，并返回删除的元素，如果队列中没有元素的话，则返回 -1
     */

}

class CQueue {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public CQueue() {
        this.stack1 = new Stack<>();
        this.stack2 = new Stack<>();
    }

    public void appendTail(int value) {
        stack1.push(value);
    }

    public int deleteHead() {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }

        if (stack2.isEmpty()) {
            return -1;
        } else {
            return stack2.pop();
        }
    }
}
