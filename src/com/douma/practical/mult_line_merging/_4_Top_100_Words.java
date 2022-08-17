package com.douma.practical.mult_line_merging;

import java.io.BufferedReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * 第四步：利用 100 大小的小顶堆得到出现频率 top 100 的单词
 * 到这里，经过外部排序后，文件中所有的单词都是有序的，相同的单词都是挨着的
 * 所以，可以顺序遍历有序的文件，得到出现频率 top 100 的单词
 */
public class _4_Top_100_Words {

    class Pair {
        String word;
        int cnt;

        Pair(String word, int cnt) {
            this.word = word;
            this.cnt = cnt;
        }
    }

    public String[] top_100 (String fileName) throws Exception {

        // 1. 初始化一个 100 大小的小顶堆
        // 堆中每个节点存放的是单词及其出现的次数
        PriorityQueue<Pair> minHeap = new PriorityQueue<>(100, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                // 按照单词出现的次数排序
                // 出现次数多的，放在堆顶
                return o1.cnt - o2.cnt;
            }
        });


        // 前一个单词
        String prevWord = null;
        // 前一个单词出现的次数
        int prevCnt = 0;

        BufferedReader br = FileIOUtils.getReader(fileName);
        // 当前的单词
        String currWord = null;
        // 2. 读取有序文件中每一行的单词，然后统计其出现的次数，并保留出现次数 top 100 的单词
        while ((currWord = br.readLine()) != null) {
            // 如果当前的单词和前一个单词不是同一个单词
            // 那么需要处理前一个单词
            if (!currWord.equals(prevWord)) {
                // 如果堆的大小小于 100，那么直接将前一个单词及其出现的次数放入堆中
                if (minHeap.size() < 100) {
                    minHeap.add(new Pair(prevWord, prevCnt));
                } else if (prevCnt > minHeap.peek().cnt) { // 否则，如果前一个单词出现的次数大于堆顶单词出现的次数
                    // 先删除堆顶单词
                    minHeap.remove();
                    //将前一个单词及其出现的次数放入堆中
                    minHeap.add(new Pair(prevWord, prevCnt));
                }

                // 将当前单词设置为前一个单词
                prevWord = currWord;
                // 前一个单词出现的次数清零
                prevCnt = 0;
            }
            // 统计前一个单词出现的次数
            prevCnt++;
        }

        //3. 最终堆中的 100 个单词就是出现频率最高的单词了，输出即可
        String[] res = new String[100];
        int index = 0;
        while (!minHeap.isEmpty()) {
            res[index++] = minHeap.poll().word;
        }

        return res;
    }

    public static void main(String[] args) throws Exception {
        String fileName = "data\\top100\\sorted_words.txt";
        String[] res = new _4_Top_100_Words().top_100(fileName);
        System.out.println(Arrays.toString(res));
    }

}
