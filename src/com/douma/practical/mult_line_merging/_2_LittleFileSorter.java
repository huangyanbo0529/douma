package com.douma.practical.mult_line_merging;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * 第二步：将每个小文件中的单词进行排序
 *  排序后的数据写到另一个目录：data\top100\sorted_data\
 */
public class _2_LittleFileSorter {

    public void sortEachFile(String dirName) throws IOException {
        File dir = new File(dirName);
        File[] littleFiles = dir.listFiles();

        // 排序每一个小文件中的单词
        for (int i = 0; i < littleFiles.length; i++) {
            // 1. 将当前小文件中单词读取到内存中
            BufferedReader br = FileIOUtils.getReader(littleFiles[i].getName());
            List<String> words = new ArrayList<>();
            String line = null;
            while ((line = br.readLine()) != null) {
                words.add(line);
            }

            FileIOUtils.closeReader(br);

            // 2. 对当前文件中的所有单词进行排序
            Collections.sort(words);

            // 3. 将排完序的单词写道目标文件中
            BufferedWriter bw = FileIOUtils.getWriter("data\\top100\\sorted_data\\" + i);
            for (String word : words) {
                bw.write(word);
                bw.newLine();
            }
            FileIOUtils.closeWriter(bw);
        }

    }

    public static void main(String[] args) throws IOException {
        String dir = "data\\top100\\raw_data";
        new _2_LittleFileSorter().sortEachFile(dir);
    }

}
