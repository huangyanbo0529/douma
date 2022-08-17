/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/
#ifndef CPP_CODE_GRAPH_H
#define CPP_CODE_GRAPH_H

#include <vector>
#include <string>
using namespace std;

// c++ 没有内置的 split ，需要自己写一个
static void split(const string &s, vector<string> &v, const string &c) {
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (string::npos != pos2) {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}

class Graph {
public:
    /**
     * 获取图的边数
     * @return
     */
    virtual int getE() = 0;

    /**
     * 获取图的顶点数
     * @return
     */
    virtual int getV() = 0;

    /**
     * 判断两个指定的顶点之间是否有边
     * @param v
     * @param w
     * @return
     */
    virtual bool hasEdge(int v, int w) = 0;

    /**
     * 获取指定顶点所有相邻的顶点
     * @param v
     * @return
     */
    virtual std::vector<int> adj(int v) = 0;

    /**
     * 获取指定顶点的度数
     * @param v
     * @return
     */
    virtual int degree(int v) = 0;

    /**
     * 返回该图的字符串形式
     * @return
     */
    virtual string toString() = 0;
};

#endif //CPP_CODE_GRAPH_H
