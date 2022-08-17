/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <stack>
#include "../AdjSet.cpp"

class CycleDetection1 {
public:
    CycleDetection1(Graph &g): g(g) {
        this->visited.resize(g.getV());
        std::fill(this->visited.begin(), this->visited.end(), false);

        // 遍历图中每个顶点
        for (int v = 0; v < g.getV(); ++v) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (!visited[v]) {
                if (dfs(v, v)) {
                    hasCycle = true;
                    break;
                }
            }
        }
    }

    bool getHasCycle() {
        return hasCycle;
    }

private:
    Graph &g;
    bool hasCycle = false;
    // 用于防止一个节点被重复访问
    vector<bool> visited;

    bool dfs(int v, int prev) {
        visited[v] = true;
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                // 后面的循环就可以不执行了
                if (dfs(w, v)) return true;
            } else { // 否则，w 顶点已经被访问
                // 如果 w 不是 v 的前一个节点的话，那么就存在环
                if (w != prev) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    AdjSet g("C:/workspace/douma-algo/data/graph-dfs.txt");
    CycleDetection1 cd(g);
    cout << to_string(cd.getHasCycle()) << endl;
    return 0;
}