/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <queue>
#include "./GraphImpl.cpp"

class TopologySortBFS {
private:
    GraphImpl g;
    vector<int> res;
    bool hasCycle = false;

public:
    TopologySortBFS(GraphImpl g): g(g) {
        if (!g.getIsDirected()) {
            throw "只能对有向图进行拓扑排序";
        }

        vector<int> indegrees;
        for (int v = 0; v < g.getV(); v++) {
            indegrees.push_back(g.indegree(v));
        }

        queue<int> q;
        for (int v = 0; v < g.getV(); v++) {
            if (indegrees[v] == 0) {
                q.push(v);
            }
        }
        res.resize(g.getV());
        int index = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            res[index++] = v;
            for (int w : g.adj(v)) {
                indegrees[w]--;
                if (indegrees[w] == 0) {
                    q.push(w);
                }
            }
        }
        if (index != g.getV()) {
            hasCycle = true;
        }
    }

    bool getIsHasCycle() {
        return hasCycle;
    }

    vector<int> getRes() {
        return res;
    }
};

int main() {
    GraphImpl g("C:/workspace/douma-algo/data/directedgraph-dfs.txt", true);
    TopologySortBFS topologySortBfs(g);
    vector<int> res = topologySortBfs.getRes();
    stringstream fmt;
    for (int v : res) {
        fmt << to_string(v) << ", ";
    }
    cout << fmt.str() << endl;
    return 0;
}