package com.douma.practical.underground;

import java.util.Objects;

/**
 * @官方网站 : https://douma.ke.qq.com
 * @微信公众号 : 抖码课堂
 * @官方微信号 : bigdatatang01
 * @作者 : 老汤
 */
public class StartEnd {
    private String start;
    private String end;

    public StartEnd(String start, String end) {
        this.start = start;
        this.end = end;
    }

    public String getStart() {
        return start;
    }

    public String getEnd() {
        return end;
    }


    // bug 修复，需要加上 equals 和 hashCode 两个方法
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        StartEnd startEnd = (StartEnd) o;
        return Objects.equals(start, startEnd.start) &&
                Objects.equals(end, startEnd.end);
    }

    @Override
    public int hashCode() {
        return Objects.hash(start, end);
    }
}
