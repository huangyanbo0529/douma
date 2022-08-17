package com.douma.line.queue;

/**
 * @微信公众号 : 抖码课堂
 * @官方微信号 : bigdatatang01
 * @作者 : 老汤
 *
 * 这个类使用另一种方式来表明循环队列是否空或者满：
 * head == tail && size == data.length 表示满了，
 * head == tail && size == 0 表示空了
 */
public class LoopQueue1<E> implements Queue<E> {
    private E[] data;
    private int head;
    private int tail;

    private int size;

    public LoopQueue1() {
        this(20);
    }

    public LoopQueue1(int capacity) {
        data = (E[])new Object[capacity];
        head = tail = 0;
        size = 0;
    }

    @Override
    public int getSize() {
        return size;
    }

    @Override
    public void enqueue(E e) {
        if (size == data.length) {
            // 队列满了
            resize(data.length * 2);
        }
        data[tail] = e;
        size++;
        tail = (tail + 1) % data.length;
    }

    @Override
    public E dequeue() { // O(1)
        if (isEmpty()) {
            throw new RuntimeException("dequeue error, No Element for dequeue");
        }
        E res = data[head];
        data[head] = null;
        size--;
        head = (head + 1) % data.length;
        if (size == data.length / 4) {
            resize(data.length / 2);
        }
        return res;
    }

    private void resize(int newCapacity) {
        E[] newData = (E[])new Object[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[(i + head) % data.length];
        }
        data = newData;
        head = 0;
        tail = size;
    }

    @Override
    public E getFront() {
        if (isEmpty()) {
            throw new RuntimeException("dequeue error, No Element for dequeue");
        }
        return data[head];
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(String.format("Queue：size = %d, capacity = %d\n", size, data.length));
        sb.append(" 队首 [");
        for (int i = head; i != tail ; i = (i + 1) % data.length) {
            sb.append(data[i]);
            if ((i + 1) % data.length != tail) {
                sb.append(",");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}
