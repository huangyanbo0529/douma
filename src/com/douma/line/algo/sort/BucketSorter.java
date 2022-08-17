package com.douma.line.algo.sort;


import java.util.ArrayList;
import java.util.Arrays;

/**
 * @微信公众号 : 抖码课堂
 * @官方微信号 : bigdatatang01
 * @作者 : 老汤
 */
public class BucketSorter {
    public void sort(int[] data) {
        if (data == null || data.length <= 1) return;

        // 1. 创建几个空的 bucket
        int maxValue = data[0];
        for (int d : data) {
            maxValue = Math.max(maxValue, d);
        }
        /*
        这里为什么是除以 10 呢？
        在视频中，我们讲过，假设数组中的元素的大小是 0 到 39
        然后我们想划分成 4 个桶，所以 39 / 10 + 1 = 4

        这里需要注意的是：bucketNum 的计算是根据场景确定的，不同的场景 bucketNum 的计算方式是不同的
        所以 bucketNum 的计算之前，需要确定桶排序使用的场景
         */
        int bucketNum = maxValue / 10 + 1; // 39 / 10 + 1 = 4
        ArrayList<Integer>[] buckets = new ArrayList[bucketNum];

        // 2. 将所有的元素添加进对应的 bucket
        for (int i = 0; i < data.length; i++) {
            // 计算当前元素应该被分配到哪一个桶里
            int index = data[i] / 10;
            if (buckets[index] == null) {
                buckets[index] = new ArrayList<>();
            }
            buckets[index].add(data[i]);
        }

        // 3. 对每一个 bucket 中的元素进行排序
        for (int i = 0; i < bucketNum; i++) {
            ArrayList<Integer> bucketData = buckets[i];
            if (bucketData != null) {
                new IntegerArrayQuickSorter().sort(bucketData);
            }
        }

        // 4. 从 buckets 中拿到排序后的数组
        int index = 0;
        for (int i = 0; i < bucketNum; i++) {
            ArrayList<Integer> bucketData = buckets[i];
            if (bucketData != null) {
                for (int j = 0; j < bucketData.size(); j++) {
                    data[index++] = bucketData.get(j);
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] data = new int[]{2, 5, 1, 23, 22, 33, 56, 12, 5, 3, 5, 6, 8, 2, 3, 4};
        new BucketSorter().sort(data);
        System.out.println(Arrays.toString(data));
    }
}
