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

class WeightedGraphImpl: public Graph {
private:
    int V;
    int E;
    vector<map<int, int>> adjMap; // 邻接表

    bool isDirected;

    vector<int> indegrees;
    vector<int> outdegrees;

    void validateVertex(int v) {
        if (v < 0 || v >= V) {
            throw "顶点 " + to_string(v) + " 不合格";
        }
    }

public:
    WeightedGraphImpl(string filename, bool isDirected): isDirected(isDirected) {
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

                indegrees.resize(V);
                fill(indegrees.begin(),  indegrees.end(), 0);
                outdegrees.resize(V);
                fill(outdegrees.begin(),  outdegrees.end(), 0);

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
            // 如果是有向图的话，统计顶点的出度和入度
            if (isDirected) {
                outdegrees[a]++;
                indegrees[b]++;
            }
            if (!isDirected) {
                adjMap[b][a] = weight;
            }
        }
    }

    bool getIsDirected() {
        return isDirected;
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
        if (isDirected) {
            throw "只有无向图才可以计算顶点的度数";
        }
        return adj(v).size();
    }

    int indegree(int v) {
        if (!isDirected) {
            throw "只有有向图才可以计算顶点的入度";
        }
        validateVertex(v);
        return indegrees[v];
    }

    int outdegree(int v) {
        if (!isDirected) {
            throw "只有有向图才可以计算顶点的出度";
        }
        validateVertex(v);
        return outdegrees[v];
    }

    string toString() {
        stringstream fmt;
        fmt << "顶点数 = " << to_string(V) << "，边数 = " << to_string(E);
        fmt << " isDirected = " << isDirected << " \n";
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


int main() {
    WeightedGraphImpl adjSet("C:/workspace/douma-algo/data/weighted-graph.txt", true);
    cout << adjSet.toString() << endl;

    vector<int> res = adjSet.adj(2);
    return 0;
}
