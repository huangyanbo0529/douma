/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <queue>
#include "./GraphImpl.cpp"

class GraphBFS {
public:
    GraphBFS(Graph &g): g(g) {
        this->visited.resize(g.getV());
        std::fill(this->visited.begin(), this->visited.end(), false);

        // 遍历图中每个顶点
        for (int v = 0; v < g.getV(); ++v) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (!visited[v]) {
                bfs(v);
            }
        }
    }

    vector<int> getRes() {
        return res;
    }

private:
    Graph &g;
    vector<int> res;
    // 用于防止一个节点被重复访问
    vector<bool> visited;

    void bfs(int v) {
        queue<int> q;
        q.push(v);
        visited[v] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (auto& w : g.adj(curr)) {
                if (!visited[w]) {
                    q.push(w);
                    visited[w] = true;
                }
            }
        }
    }
};

int main() {
    GraphImpl g("C:/workspace/douma-algo/data/directedgraph-dfs.txt", true);
    GraphBFS graphBfs(g);
    vector<int> res = graphBfs.getRes();
    stringstream fmt;
    for (int v : res) {
        fmt << to_string(v) << ", ";
    }
    cout << fmt.str() << endl;
    return 0;
}