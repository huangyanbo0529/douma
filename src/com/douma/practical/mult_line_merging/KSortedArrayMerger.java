package com.douma.practical.mult_line_merging;

import java.util.*;

/**
 * 抖码算法，让算法学习变的简单有趣
 *
 * @作者 : 老汤
 */
public class KSortedArrayMerger {

    /**
     * 多路归并排序
     * 给定 k 个升序的数组，将它们合并成一个有序的数组
     * 例如：
     *  输入： k = 3
     *      a = [1, 2, 6, 9, 10]
     *      b = [2, 3, 7, 11]
     *      c = [4, 8, 9, 13]
     *      d = [5]
     *  输出：
     *      [1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13]
     *
     *  tips：使用小顶堆实现排序
     *
     *  假设每个数组的平均长度为 n
     *  时间复杂度：O(n*k*log(k))
     *  空间复杂度：O(n*k)
     */
    public int[] mergeKSortedArray(List<int[]> data, int k) {
        // 1. 计算合并之后的数组的总长度
        int len = 0;
        for (int i = 0; i < k; i++) {
            len += data.get(i).length;
        }

        // 2. 初始化结果数组
        int[] res = new int[len];

        // 3. 初始化一个大小为 k 的小顶堆
        // 小顶堆中的每个节点存储 3 个值： [value, whichArray, valueIndex]
        // value 表示数组中的元素值
        // whichArray 表示 value 所属的数组
        // valueIndex 表示 value 在所属数组中的索引
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(k, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                // 先按照 value 排序，value 小的放在堆顶
                // value 相等的话，按照 value 所属的数组在 data 中的索引排序，如果小的放在堆顶，这个其实排不排序都无所谓
                return o1[0] != o2[0] ? o1[0] - o2[0] : o1[1] - o2[1];
            }
        });

        // 4. 将 k 个数组的第一个元素值都放入到堆中
        for (int i = 0; i < k; i++) {
            if (data.get(i).length == 0) continue;
            minHeap.add(new int[]{data.get(i)[0], i, 0});
        }

        // 5. 合并排序
        int index = 0;
        while (!minHeap.isEmpty()) {
            // 5.1 拿到堆顶最小的元素
            int[] record = minHeap.poll();
            int value = record[0];
            int whichArray = record[1];
            int valueIndex = record[2];

            // 5.2 将最小元素放入到结果中
            res[index++] = value;

            // 5.3 处理这个 value 所在的数组的下一个元素
            valueIndex++;
            // 如果没有下一个元素了，则不做任何处理
            if (valueIndex == data.get(whichArray).length) continue;
            // 将下一个元素及其位置信息放入到堆中
            minHeap.add(new int[]{data.get(whichArray)[valueIndex], whichArray, valueIndex});
        }

        return res;
    }

    public static void main(String[] args) {
        int[] a = {1, 2, 6, 9, 10};
        int[] b = {2, 3, 7, 11};
        int[] c = {4, 8, 9, 13};
        int[] d = {5};

        List<int[]> data = new ArrayList<>();
        data.add(a);
        data.add(b);
        data.add(c);
        data.add(d);

        int[] res = new KSortedArrayMerger().mergeKSortedArray(data, 4);
        System.out.println(Arrays.toString(res));
    }
}
