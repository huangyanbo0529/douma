/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <queue>
#include "../AdjSet.cpp"

class CC {
public:
    CC(AdjSet g): g(g) {
        this->visited.resize(g.getV());
        std::fill(this->visited.begin(), this->visited.end(), -1);

        // 遍历图中每个顶点
        for (int v = 0; v < g.getV(); ++v) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (visited[v] == -1) {
                ccCount++;
                bfs(v, ccCount);
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
    AdjSet g;
    int ccCount = 0;
    // 用于防止一个节点被重复访问
    vector<int> visited;

    void bfs(int v, int ccId) {
        queue<int> q;
        q.push(v);
        // 维护节点所属的连通分量
        visited[v] = ccId;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto& w : g.adj(curr)) {
                if (visited[w] == -1) {
                    q.push(w);
                    // 维护节点所属的连通分量
                    visited[w] = ccId;
                }
            }
        }
    }

    void validateVertex(int v) {
        if (v < 0 || v >= g.getV()) {
            throw "顶点 " + to_string(v) + " 不合格";
        }
    }
};

int main() {
    AdjSet g("C:/workspace/douma-algo/data/graph-bfs.txt");
    CC cc(g);
    cout << to_string(cc.getCcCount()) << endl;
    return 0;
}