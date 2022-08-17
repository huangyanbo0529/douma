package com.douma.practical.mult_line_merging;

import java.io.*;

/**
 * 第一步：将一个大文件切割成多个小文件
 * 小文件的大小为 512kb 左右
 * 小文件都写到这个目录下：data\top100\raw_data\
 */
public class _1_FileSplit {

    public void splitFile(String fileName) throws IOException {
        int fileNum = 0;
        String fileSuffix = "data\\top100\\raw_data\\";
        String littleFileName = fileSuffix + fileNum;

        // 记录每个小文件的大小
        long totalSize = 0;

        BufferedWriter bw = FileIOUtils.getWriter(littleFileName);

        BufferedReader br = FileIOUtils.getReader(fileName);
        String line = null;
        while ((line = br.readLine()) != null) {
            // 如果当前小文件大小大于 512KB ，那么关闭当前小文件，写下一个小文件
            if (totalSize >= 512 * 1024) {
                // 关闭当前小文件的输出流
                FileIOUtils.closeWriter(bw);

                // 拿到下一个小文件的输出流，开始写下一个小文件
                fileNum++;
                littleFileName = fileSuffix + fileNum;
                bw = FileIOUtils.getWriter(littleFileName);
                totalSize = 0;
            }

            totalSize += line.length();

            bw.write(line);
            bw.newLine();
        }

        FileIOUtils.closeReader(br);
        FileIOUtils.closeWriter(bw);
    }

    public static void main(String[] args) throws IOException {
        String fileName = "data\\top100\\words.txt";
        new _1_FileSplit().splitFile(fileName);
    }
}
