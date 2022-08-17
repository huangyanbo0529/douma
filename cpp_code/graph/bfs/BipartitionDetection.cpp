/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <queue>
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
                if (!bfs(v)) {
                    isBipartition = false;
                    break;
                }
            }
        }
    }

    bool getIsBipartition() {
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

    bool bfs(int v) {
        queue<int> q;
        q.push(v);
        visited[v] = true;

        colors[v] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto& w : g.adj(curr)) {
                // 如果 w 没有遍历过，则需要染色
                if (!visited[w]) {
                    q.push(w);
                    visited[w] = true;
                    // 给顶点 w 染色，和 curr 的颜色不一样
                    colors[w] = 1 - colors[curr];
                } else if (colors[w] == colors[curr]) {
                    // 如果 w 被访问过，并且它的颜色和相邻点一样
                    // 那么可以判定不是二分图
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    AdjSet g("C:/workspace/douma-algo/data/graph-bfs.txt");
    BipartitionDetection bpd(g);
    cout << to_string(bpd.getIsBipartition()) << endl;
    return 0;
}