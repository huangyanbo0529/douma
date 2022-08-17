package com.douma.highlevel.set;

/**
 * @官方网站 : https://douma.ke.qq.com
 * @微信公众号 : 抖码课堂
 * @官方微信号 : bigdatatang01
 * @作者 : 老汤
 */
public class HashSet2<E> implements Set<E> {
    private class Item<E> {
        E data;
        boolean isDeleted;

        public Item(E data) {
            this.data = data;
            this.isDeleted = false;
        }

        @Override
        public int hashCode() {
            return data.hashCode();
        }
    }

    private Item<E>[] items;
    private int size;
    private int deleteCount; // 用于记录有多少标记删除的元素
    // 装载因子
    private double loadFactor = 0.75;

    public HashSet2() {
        items = new Item[10];
        this.size = 0;
        this.deleteCount = 0;
    }

    public HashSet2(int loadFactor) {
        this();
        this.loadFactor = loadFactor;
    }

    private int hash(E e, int length) {
        return Math.abs(e.hashCode()) % length;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public void add(E e) { // 最好：O(1)，最坏：O(n)
        int index = hash(e, items.length);

        // addIndex 表示元素 e 需要插入的索引位置
        int addIndex = index;
        // isFirst 用于辅助找到元素 e 插入的位置
        boolean isFirst = true;

        // bug 修复：add 前先判断是否存在元素 e
        while (items[index] != null && !e.equals(items[index].data)) {
            // 找到第一个等于 null 或者删除的元素，并记录赋值给 addIndex
            if ((items[index] == null || items[index].isDeleted) && isFirst) {
                isFirst = false;
            }

            index++;
            index = index % items.length;
        }
        // 插入索引
        addIndex = index;
        // 说明已经存在 e，则直接返回
        if (items[index] != null && !items[index].isDeleted) return;

        // 这个时候的 addIndex 对应的元素要么是 null ，要么是已经删除的元素
        // 如果 addIndex 对应的元素是标记为删除的元素，那么直接被覆盖了，标记为删除的元素个数减少 1
        if (items[addIndex] != null && items[addIndex].isDeleted) deleteCount--;
        items[addIndex] = new Item(e);
        size++;

        if (size >= items.length * loadFactor) {
            resize(2 * items.length);
        }

    }

    private void resize(int newCapacity) {
        Item<E>[] newData = new Item[newCapacity];
        for (int i = 0; i < items.length; i++) {
            if (items[i] != null && !items[i].isDeleted) {
                int newIndex = hash(items[i].data, newCapacity);
                newData[newIndex] = items[i];
            }
        }
        // 所有标记为删除的元素都清理掉了
        deleteCount = 0;
        items = newData;
    }

    @Override
    public void remove(E e) { // 最好：O(1)，最坏：O(n)
        int index = hash(e, items.length);
        // 找到等于 e 或者元素为 null 的索引
        while (items[index] != null && !e.equals(items[index].data)) {
            index++;
            index = index % items.length;
        }
        if (items[index] != null) {
            items[index].isDeleted = true;
            size--;
            deleteCount++;
        }
        // 如果标记为删除的元素太多的话，我们进行 resize，清除标记为删除的元素
        // TODO：这里可能会产生时间复杂度震荡
        if (deleteCount + size >= items.length * loadFactor) {
            resize(items.length);
        }
    }

    @Override
    public boolean contains(E e) { // 最好：O(1)，最坏：O(n)
        int index = hash(e, items.length);

        // 找到等于 e 或者元素为 null 的索引
        while (items[index] != null && !e.equals(items[index].data)) {
            index++;
            index = index % items.length;
        }

        return items[index] != null && !items[index].isDeleted;
    }

    public static void main(String[] args) {
        Set<Integer> set = new HashSet2<>();
        set.add(11);
        set.add(21);

        System.out.println(set.contains(21));
        System.out.println(set.contains(11));

    }
}
