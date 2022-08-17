/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <climits>
#include <queue>
#include "WeightedAdjSet.cpp"
#include "Prime.h"
#include "../dfs/CC1.cpp"

// 时间复杂度：O(E*logE)
class Prime1 {
private:
    WeightedAdjSet g;
    vector<WeightedEdge> res;

public:
    Prime1(WeightedAdjSet g): g(g) {
        // g 是连通图
        CC1 cc(g);
        if (cc.getCcCount() > 1) return;

        // Prim
        vector<bool> visited(g.getV(), false);
        // 选择顶点 0 作为切分的一部分
        visited[0] = true;
        // 小顶堆
        priority_queue<WeightedEdge, vector<WeightedEdge>, decltype(&compareWeightedEdge)> pq(compareWeightedEdge);
        for (int w : g.adj(0)) {
            pq.push(WeightedEdge(0, w, g.getWeight(0, w)));
        }
        while (!pq.empty()) { // O(E)
            // 1. 拿到最小横切边
            WeightedEdge minEdge = pq.top(); // O(logE)
            pq.pop();
            if (visited[minEdge.v] && visited[minEdge.w]) {
                // 不是横切边
                continue;
            }

            // 2. 加入到最小生成树中
            res.push_back(minEdge);

            // 3. 扩展切分
            int newV = visited[minEdge.v] ? minEdge.w : minEdge.v;
            visited[newV] = true;
            // 将新的横切边放入到优先队列
            for (int w : g.adj(newV)) {
                if (!visited[w]) {
                    pq.push(WeightedEdge(newV, w, g.getWeight(newV, w)));
                }
            }
        }
    }

    vector<WeightedEdge> getResult() {
        return res;
    }

};

int main() {
    WeightedAdjSet weightedAdjSet("C:/workspace/douma-algo/data/prim.txt");
    Prime1 prime(weightedAdjSet);
    vector<WeightedEdge> res = prime.getResult();
    for (int i = 0; i < res.size(); ++i) {
        std:cout << res[i].toString() << endl;
    }
    return 0;
}