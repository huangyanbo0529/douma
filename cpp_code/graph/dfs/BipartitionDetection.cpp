/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <stack>
#include "../AdjSet.cpp"

class BipartitionDetection {
public:
    BipartitionDetection(Graph &g): g(g) {
        this->visited.resize(g.getV());
        std::fill(this->visited.begin(), this->visited.end(), false);
        this->colors.resize(g.getV());
        std::fill(this->colors.begin(), this->colors.end(), -1);

        // 遍历图中每个顶点
        for (int v = 0; v < g.getV(); ++v) {
            // 先判断，没有遍历的顶点才能进行深度优先遍历
            if (!visited[v]) {
                if (!dfs(v, 0)) {
                    isBipartition = false;
                    break;
                }
            }
        }
    }

    bool getisBipartition() {
        return isBipartition;
    }

private:
    Graph &g;
    // -1 表示没有染颜色
    // 0 红色 1 蓝色
    vector<int> colors;
    // 用于防止一个节点被重复访问
    vector<bool> visited;

    bool isBipartition = true;

    bool dfs(int v, int color) {
        visited[v] = true;
        colors[v] = color;
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                // 如果 v 的颜色是 1，那么 w 的颜色就是 0
                // 如果 v 的颜色是 0，那么 w 的颜色就是 1
                if (!dfs(w, 1 - color)) return false;
            } else if (colors[w] == colors[v]) {
                // 如果相邻顶点的颜色一样的话，则不是二分图
                return false;
            }
        }
        return true;
    }
};

int main() {
    AdjSet g("C:/workspace/douma-algo/data/graph-dfs.txt");
    BipartitionDetection bpd(g);
    cout << to_string(bpd.getisBipartition()) << endl;
    return 0;
}