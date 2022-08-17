/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <stack>
#include "../AdjSet.cpp"

class CC {
public:
    CC(Graph &g): g(g) {
        this->visited.resize(g.getV());
        std::fill(this->visited.begin(), this->visited.end(), false);

        // 遍历图中每个顶点
        for (int v = 0; v < g.getV(); ++v) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (!visited[v]) {
                ccCount++;
                dfs(v);
            }
        }
    }

    int getCcCount() {
        return ccCount;
    }

private:
    Graph &g;
    int ccCount = 0;
    // 用于防止一个节点被重复访问
    vector<bool> visited;

    void dfs(int v) {
        visited[v] = true;
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                dfs(w);
            }
        }
    }
};

int main() {
    AdjSet g("C:/workspace/douma-algo/data/graph-dfs.txt");
    CC cc(g);
    cout << to_string(cc.getCcCount()) << endl;
    return 0;
}