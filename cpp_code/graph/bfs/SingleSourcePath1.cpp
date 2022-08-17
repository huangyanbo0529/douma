/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <queue>
#include <algorithm>
#include "../AdjSet.cpp"

class SingleSourcePath1 {
public:
    SingleSourcePath1(Graph &g, int source, int target): g(g), source(source), target(target) {
        this->visited.resize(g.getV());
        std::fill(this->visited.begin(), this->visited.end(), false);
        this->prevs.resize(g.getV());
        std::fill(this->prevs.begin(), this->prevs.end(), -1);

        bfs(source);
    }

    bool isConnected() {
        validateVertex(target);
        return visited[target];
    }

    vector<int> path() {
        vector<int> res;
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

private:
    Graph &g;
    int source;
    int target;
    // 用于防止一个节点被重复访问
    vector<bool> visited;
    // 存储每个顶点的前一个顶点，初始化为 -1
    vector<int> prevs;

    void bfs(int v) {
        queue<int> q;
        q.push(v);
        visited[v] = true;
        // 维护顶点的前一个顶点
        prevs[v] = v;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr == target) {
                return;
            }
            for (auto& w : g.adj(curr)) {
                if (!visited[w]) {
                    q.push(w);
                    visited[w] = true;
                    // 维护顶点的前一个顶点
                    prevs[w] = curr;
                }
            }
        }
    }

    void validateVertex(int v) {
        if (v < 0 || v >= g.getV()) {
            throw "顶点 " + to_string(v) + " 不合格";
        }
    }
};

int main() {
    AdjSet g("C:/workspace/douma-algo/data/graph-bfs.txt");
    SingleSourcePath1 ssp(g, 0, 6);
    vector<int> res = ssp.path();
    stringstream fmt;
    for (int v : res) {
        fmt << to_string(v) << ", ";
    }
    cout << fmt.str() << endl;
    return 0;
}