package com.douma.practical.mult_line_merging;

import java.io.BufferedReader;
import java.io.IOException;

// BufferedIterator 是对文件输入流 BufferedReader 的包装，用于：
//  ① 判断输入流中是否还有数据，有过有的话，则先缓存下一行数据
//  ② 得到文件输入流中的下一行数据
public class BufferedIterator {

    private BufferedReader reader;
    private String head;

    BufferedIterator(BufferedReader reader) {
        this.reader = reader;
    }

    public boolean hasNext() {
        try {
            head = this.reader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
            head = null;
        }
        return head != null;
    }

    public String next() {
        return head;
    }

    public void close() throws Exception {
        this.reader.close();
    }
}
