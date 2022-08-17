/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <algorithm>
#include "../AdjSet.cpp"

class TwoVertexPath {
public:
    TwoVertexPath(Graph &g, int source, int target): g(g), source(source), target(target) {
        this->visited.resize(g.getV());
        std::fill(this->visited.begin(), this->visited.end(), false);
        this->prevs.resize(g.getV());
        std::fill(this->prevs.begin(), this->prevs.end(), -1);

        // 深度优先遍历，这里只需要从指定的源顶点遍历就可以
        // 源顶点的前一个顶点设置为源顶点本身
        dfs(source, source);

        // 计算一次
        path();
    }

    bool isConnected() {
        validateVertex(target);
        return visited[target];
    }

    vector<int> path() {
        // 1. 如果源顶点到不了目标顶点，直接返回
        if (!isConnected()) {
            return res;
        }

        // 2. 根据 prevs 信息找到路径
        int tmp = target;
        while (tmp != source) {
            res.push_back(tmp);
            tmp = prevs[tmp];
        }
        res.push_back(source);

        // 3. 翻转
        reverse(res.begin(), res.end());

        return res;
    }

    vector<int> getRes() {
        return res;
    }


private:
    Graph &g;
    int source;
    int target;
    // 存储每个顶点的前一个顶点，初始化为 -1
    vector<int> prevs;
    // 用于防止一个节点被重复访问
    vector<bool> visited;

    vector<int> res;

    // 递归遍历顶点 v，并且维护顶点 v 的前一个顶点的信息
    bool dfs(int v, int prev) {
        visited[v] = true;
        // 维护顶点 v 的前一个顶点
        prevs[v] = prev;
        if (v == target) return true;
        for (int w : g.adj(v)) {
            if (!visited[w]) {
                // v 是 w 的前一个顶点
                // 如果已经找到了，不用再去遍历 v 的下一个相邻节点了
                if (dfs(w, v)) return true;
            }
        }
        return false;
    }

    void validateVertex(int v) {
        if (v < 0 || v >= g.getV()) {
            throw "顶点 " + to_string(v) + " 不合格";
        }
    }
};

int main() {
    AdjSet g("C:/workspace/douma-algo/data/graph-bfs.txt");
    TwoVertexPath ttp(g, 0, 6);
    vector<int> res = ttp.getRes();
    stringstream fmt;
    for (int v : res) {
        fmt << to_string(v) << ", ";
    }
    cout << fmt.str() << endl;
    return 0;
}