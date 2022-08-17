/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <stack>
#include "./GraphImpl.cpp"

class GraphDFSR {
public:
    GraphDFSR(Graph &g): g(g) {
        this->visited.resize(g.getV());
        std::fill(this->visited.begin(), this->visited.end(), false);

        // 遍历图中每个顶点
        for (int v = 0; v < g.getV(); ++v) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (!visited[v]) {
                dfs(v);
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

    void dfs(int v) {
        res.push_back(v);
        visited[v] = true;
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                dfs(w);
            }
        }
    }
};

int main() {
    GraphImpl g("C:/workspace/douma-algo/data/directedgraph-dfs.txt", true);
    GraphDFSR graphDfs(g);
    vector<int> res = graphDfs.getRes();
    stringstream fmt;
    for (int v : res) {
        fmt << to_string(v) << ", ";
    }
    cout << fmt.str() << endl;
    return 0;
}