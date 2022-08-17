/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include "../Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

class WeightedAdjSet: public Graph {
private:
    int V;
    int E;
    vector<map<int, int>> adjMap; // 邻接表

    void validateVertex(int v) {
        if (v < 0 || v >= V) {
            throw "顶点 " + to_string(v) + " 不合格";
        }
    }

public:
    WeightedAdjSet(string filename) {
        char c[100];
        ifstream reader(filename, ios::in | ios::binary);

        int i = 0;
        while (reader.getline(c, 100)) {
            string line = string (c);
            vector<string> arr;
            split(line, arr, " ");
            if (i == 0) {
                this->V = atoi(arr[0].c_str());
                this->E = atoi(arr[1].c_str());

                for (int i = 0; i < V; ++i) {
                    map<int, int> temp;
                    this->adjMap.push_back(temp);
                }
                i++;
                continue;
            }
            int a = atoi(arr[0].c_str());
            validateVertex(a);
            int b = atoi(arr[1].c_str());
            validateVertex(b);

            // 检测自环边
            if (a == b) {
                throw "出现了自环边，错误";
            }
            // 检测平行边
            if (adjMap[a].count(b)) {
                throw "出现了平行边，错误";
            }
            int weight = atoi(arr[2].c_str());
            adjMap[a][b] = weight;
            adjMap[b][a] = weight;
        }
    }

    int getV() {
        return V;
    }

    int getE() {
        return E;
    }

    // 判断两个指定的顶点之间是否有边
    // 时间复杂度：O(logV)
    bool hasEdge(int v, int w) {
        validateVertex(v);
        validateVertex(w);

        return adjMap[v].count(w);
    }

    // 获取指定边的权重值
    int getWeight(int v, int w) {
        if (hasEdge(v, w)) {
            return adjMap[v][w];
        }
        return -1;
    }

    // 获取指定顶点所有相邻的顶点
    // 时间复杂度：O(V)
    vector<int> adj(int v) {
        validateVertex(v);
        vector<int> res;
        for (auto& kv: adjMap[v]) {
            res.push_back(kv.first);
        }
        return res;
    }

    // 获取指定顶点的度数
    int degree(int v) {
        return adj(v).size();
    }

    string toString() {
        stringstream fmt;
        fmt << "顶点数 = " << to_string(V) << "，边数 = " << to_string(E) << "\n";
        for (int v = 0; v < V; v++) {
            fmt << to_string(v) << ": ";
            for (auto& w : adjMap[v]) {
                fmt << "(" << to_string(w.first) << ", " << to_string(w.second) << ")";
            }
            fmt << "\n";
        }
        string res = fmt.str();
        return res;
    }
};


/*
int main() {
    WeightedAdjSet adjSet("C:/workspace/douma-algo/data/weighted-graph.txt");
    cout << adjSet.toString() << endl;

    vector<int> res = adjSet.adj(2);
    return 0;
}*/
