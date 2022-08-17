/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>

class AdjMatrix: public Graph {
private:
    int V;
    int E;
    vector<vector<int>> matrix;

    void validateVertex(int v) {
        if (v < 0 || v >= V) {
            throw "顶点 " + to_string(v) + " 不合格";
        }
    }

public:
    AdjMatrix(string filename) {
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
                    vector<int> temp;
                    for (int j = 0; j < V; ++j) {
                        temp.push_back(0);
                    }
                    this->matrix.push_back(temp);
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
            if (matrix[a][b] == 1) {
                throw "出现了平行边，错误";
            }
            matrix[a][b] = 1;
            matrix[b][a] = 1;
        }
    }

    int getV() {
        return V;
    }

    int getE() {
        return E;
    }

    // 判断两个指定的顶点之间是否有边
    // 时间复杂度：O(1)
    bool hasEdge(int v, int w) {
        validateVertex(v);
        validateVertex(w);

        return matrix[v][w] == 1;
    }

    // 获取指定顶点所有相邻的顶点
    // 时间复杂度：O(V)
    vector<int> adj(int v) {
        validateVertex(v);

        vector<int> res;
        for (int i = 0; i < V; i++) {
            if (matrix[v][i] == 1) {
                res.push_back(i);
            }
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
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                fmt << to_string(matrix[i][j]) << " ";
            }
            fmt << "\n";
        }
        string res = fmt.str();
        return res;
    }
};

int main() {
    Graph *g = new AdjMatrix("C:/workspace/douma-algo/data/graph.txt");
    cout << g->toString() << endl;
    return 0;
}