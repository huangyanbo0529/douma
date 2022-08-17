package com.douma.line.queue;

/**
 * 抖码算法，让算法学习变的简单有趣
 *
 * @作者 : 老汤
 *
 * 数组实现普通队列，不支持动态扩容：
 *                head                    tail
 *  |     |     |  5  |  7  |  9  |  1  |      |      |      |
 *
 */
public class ArrayQueue1<E> implements Queue<E> {

    private E data[];
    private int head;
    private int tail;

    public ArrayQueue1() {
        this(20);
    }

    public ArrayQueue1(int capacity) {
        data = (E[])new Object[capacity];
        head = tail = 0;
    }

    @Override
    public int getSize() {
        return tail - head;
    }

    @Override
    public boolean isEmpty() {
        return head == tail;
    }

    @Override
    public void enqueue(E e) {
        if (tail == data.length) {
            throw new RuntimeException("enqueue error, 队列满了");
        }
        data[tail] = e;
        tail++;
    }

    @Override
    public E dequeue() {
        if (isEmpty()) {
            throw new RuntimeException("enqueue error, 队列空的");
        }
        E ret = data[head];
        head++;
        return ret;
    }

    @Override
    public E getFront() {
        if (isEmpty()) {
            throw new RuntimeException("enqueue error, 队列空的");
        }
        return data[head];
    }

    public static void main(String[] args) {
        ArrayQueue1<Integer> queue1 = new ArrayQueue1<>(5);
        queue1.enqueue(10);
        queue1.enqueue(2);
        queue1.enqueue(4);
        queue1.enqueue(3);
        System.out.println(queue1.getSize());
        System.out.println(queue1.dequeue());
        System.out.println(queue1.getSize());
        queue1.enqueue(30);
        System.out.println(queue1.dequeue());
        System.out.println(queue1.dequeue());
        System.out.println(queue1.dequeue());
        System.out.println(queue1.dequeue());
        System.out.println(queue1.dequeue());
    }
}
