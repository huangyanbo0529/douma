/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <stack>
#include "../AdjSet.cpp"

class CCMaxCount {
public:
    CCMaxCount(Graph &g): g(g) {
        this->visited.resize(g.getV());
        std::fill(this->visited.begin(), this->visited.end(), false);

        // 遍历图中每个顶点
        for (int v = 0; v < g.getV(); ++v) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (!visited[v]) {
                maxVertexNum = max(dfs(v), maxVertexNum);
            }
        }
    }

    int getMaxVertexNum() {
        return maxVertexNum;
    }

private:
    Graph &g;
    int maxVertexNum = 0;
    // 用于防止一个节点被重复访问
    vector<bool> visited;

    int dfs(int v) {
        visited[v] = true;
        int res = 1;
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                res += dfs(w);
            }
        }
        return res;
    }
};

int main() {
    AdjSet g("C:/workspace/douma-algo/data/graph-dfs.txt");
    CCMaxCount ccc(g);
    cout << to_string(ccc.getMaxVertexNum()) << endl;
    return 0;
}