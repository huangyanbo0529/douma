package com.douma.practical.mult_line_merging;

import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * 第三步： 对有序的小文件进行外部排序
 * 使用多路归并排序实现
 */
public class _3_ExternalSorter {

    public void mergeSort(String dirName) throws Exception {

        File dir = new File(dirName);
        File[] children = dir.listFiles();

        // 1. 初始化一个最小堆，大小就是有序小文件的个数
        // 堆中的每个节点存放每个有序小文件对应的输入流
        // BufferedIterator 是对文件输入流 BufferedReader 的包装，用于：
        //  ① 判断输入流中是否还有数据
        //  ② 得到文件输入流中的下一行数据
        PriorityQueue<BufferedIterator> minHeap = new PriorityQueue<>(children.length, new Comparator<BufferedIterator>() {
            @Override
            public int compare(BufferedIterator o1, BufferedIterator o2) {
                // 按照每个有序文件中的下一行数据对所有文件输入流进行排序
                // 单词小的输入文件流放在堆顶
                return o1.next().compareTo(o2.next());
            }
        });

        // 2. 将所有有序文件的输入流包装成 BufferedIterator 放入到堆中
        for (File file : children) {
            BufferedReader br = FileIOUtils.getReader(file.getName());
            BufferedIterator buf = new BufferedIterator(br);
            // 要有数据才放入到堆中，否则关闭流
            if (buf.hasNext()) {
                minHeap.add(buf);
            } else {
                buf.close();
            }
        }

        BufferedWriter bw = FileIOUtils.getWriter("data\\top100\\sorted_words.txt");
        // 3. 拿出堆顶的数据，并写入到最终排序的文件中
        while (!minHeap.isEmpty()) {
            BufferedIterator firstBuf = minHeap.poll();
            bw.write(firstBuf.next());
            bw.newLine();
            // 如果拿出来的输入流中还有数据的话，那么将这个输入流再一次添加到栈中，
            if (firstBuf.hasNext()) {
                minHeap.add(firstBuf);
            } else { // 否则说明该文件输入流中没有数据了，那么可以关闭这个流
                firstBuf.close();
            }
        }

       FileIOUtils.closeWriter(bw);
    }

    public static void main(String[] args) throws Exception {
        String dirName = "data\\top100\\sorted_data\\";
        new _3_ExternalSorter().mergeSort(dirName);
    }

}
