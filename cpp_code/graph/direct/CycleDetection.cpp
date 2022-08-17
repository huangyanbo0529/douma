/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <stack>
#include "./GraphImpl.cpp"

class CycleDetection {
public:
    CycleDetection(Graph &g): g(g) {
        this->visited.resize(g.getV());
        std::fill(this->visited.begin(), this->visited.end(), false);
        this->isOnPath.resize(g.getV());
        std::fill(this->isOnPath.begin(), this->isOnPath.end(), false);

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
    vector<bool> isOnPath;

    bool dfs(int v, int prev) {
        visited[v] = true;
        isOnPath[v] = true;
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                // 后面的循环就可以不执行了
                if (dfs(w, v)) return true;
            } else { // 否则，w 顶点已经被访问
                if (isOnPath[w]) {
                    return true;
                }
            }
        }
        isOnPath[v] = false;
        return false;
    }
};

int main() {
    GraphImpl g("C:/workspace/douma-algo/data/directedgraph-dfs.txt", true);
    CycleDetection cd(g);
    cout << to_string(cd.getHasCycle()) << endl;
    return 0;
}