/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <set>

class AdjSet: public Graph {
private:
    int V;
    int E;
    vector<set<int>> adjSet; // 邻接表

    void validateVertex(int v) {
        if (v < 0 || v >= V) {
            throw "顶点 " + to_string(v) + " 不合格";
        }
    }

public:
    AdjSet(string filename) {
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
                    set<int> temp;
                    this->adjSet.push_back(temp);
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
            if (adjSet[a].count(b)) {
                throw "出现了平行边，错误";
            }
            adjSet[a].insert(b);
            adjSet[b].insert(a);
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

        return adjSet[v].count(w);
    }

    // 获取指定顶点所有相邻的顶点
    // 时间复杂度：O(V)
    vector<int> adj(int v) {
        validateVertex(v);
        vector<int> res;
        res.assign(adjSet[v].begin(), adjSet[v].end());
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
            for (auto& w : adjSet[v]) {
                fmt << to_string(w) << " ";
            }
            fmt << "\n";
        }
        string res = fmt.str();
        return res;
    }
};


/*int main() {
    Graph *g = new AdjSet("C:/workspace/douma-algo/data/graph.txt");
    cout << g->toString() << endl;
    return 0;
}*/
