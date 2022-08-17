/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include "../AdjSet.cpp"

class CC1 {
public:
    CC1(Graph &g): g(g) {
        this->visited.resize(g.getV());
        std::fill(this->visited.begin(), this->visited.end(), -1);

        // 遍历图中每个顶点
        for (int v = 0; v < g.getV(); ++v) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (visited[v] == -1) {
                ccCount++;
                dfs(v, ccCount);
            }
        }
    }

    int getCcCount() {
        return ccCount;
    }

    vector<vector<int>> components() {
        vector<vector<int>> res;
        for (int i = 0; i < ccCount; ++i) {
            vector<int> temp;
            res.push_back(temp);
        }
        for (int v = 0; v < g.getV(); ++v) {
            int cc = visited[v];
            res[cc - 1].push_back(v);
        }
        return res;
    }

    bool isConnected(int v, int w) {
        validateVertex(v);
        validateVertex(w);
        return visited[v] == visited[w];
    }

private:
    Graph &g;
    int ccCount = 0;
    // 用于防止一个节点被重复访问
    vector<int> visited;

    void dfs(int v, int ccId) {
        visited[v] = ccId;
        for (int w : g.adj(v)) {
            if (visited[w] == -1) {
                dfs(w, ccId);
            }
        }
    }

    void validateVertex(int v) {
        if (v < 0 || v >= g.getV()) {
            throw "顶点 " + to_string(v) + " 不合格";
        }
    }
};

/*int main() {
    Graph *g = new AdjSet("C:/workspace/douma-algo/data/graph-dfs.txt");
    CC1 *cc = new CC1(*g);
    vector<vector<int>> res = cc->components();
    stringstream fmt;
    for (int i = 0; i < res.size(); ++i) {
        vector<int> temp = res[i];
        for (int j = 0; j < temp.size(); ++j) {
            fmt << to_string(res[i][j]) << ", ";
        }
        fmt << "\n";
    }
    cout << fmt.str() << endl;
    cout << to_string(cc->isConnected(0, 6)) << endl;
    return 0;
}*/
