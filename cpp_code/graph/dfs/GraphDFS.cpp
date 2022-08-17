/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <stack>
#include "../AdjSet.cpp"

class GraphDFS {
public:
    GraphDFS(Graph &g): g(g) {
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
        stack<int> s;
        s.push(v);
        visited[v] = true;

        while (!s.empty()) {
            int curr = s.top();
            s.pop();
            res.push_back(curr);
            for (auto& w : g.adj(curr)) {
                // 如果已经访问过了，就不压入栈，就不会再次访问了
                if (!visited[w]) {
                    s.push(w);
                    visited[w] = true;
                }
            }
        }
    }
};

int main() {
    Graph *g = new AdjSet("C:/workspace/douma-algo/data/graph-dfs.txt");
    GraphDFS graphDfs(*g);
    vector<int> res = graphDfs.getRes();
    stringstream fmt;
    for (int v : res) {
        fmt << to_string(v) << ", ";
    }
    cout << fmt.str() << endl;
    return 0;
}