package com.douma.practical.mult_line_merging;

import java.util.Arrays;

/**
 * 抖码算法，让算法学习变的简单有趣
 *
 * @作者 : 老汤
 */
public class TwoSortedArrayMerger {

    /**
     * 给定两个升序的数组，将它们合并成一个有序的数组
     * 例如：
     *  输入：
     *      a = [1, 2, 6, 9, 10]
     *      b = [2, 3, 7, 11]
     *  输出：
     *      [1, 2, 2, 3, 6, 7, 9, 10, 11]
     *
     *  tips：其实就是我们前面讲解归并排序的合并过程
     *
     *  时间复杂度：O(m + n)
     *  空间复杂度：O(m + n)
     */
    public int[] mergeTwoSortedArray(int[] a, int[] b) {
        int m = a.length, n = b.length;
        int[] res = new int[m + n];

        int i = 0, j = 0;
        int index = 0;
        for (int k = 0; k < res.length; k++) {
            if (i == m) {
                res[index++] = b[j++];
            } else if (j == n) {
                res[index++] = a[i++];
            } else if (a[i] < b[j]) {
                res[index++] = a[i++];
            } else {
                res[index++] = b[j++];
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[] a = {1, 2, 6, 9, 10};
        int[] b = {2, 3, 7, 11};
        int[] res = new TwoSortedArrayMerger().mergeTwoSortedArray(a, b);
        System.out.println(Arrays.toString(res));
    }
}
