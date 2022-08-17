/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <climits>
#include "WeightedAdjSet.cpp"
#include "Prime.h"
#include "../dfs/CC1.cpp"

// 时间复杂度：O(V*V*E)
class Prime {
private:
    WeightedAdjSet g;
    vector<WeightedEdge> res;

public:
    Prime(WeightedAdjSet g): g(g) {
        // g 是连通图
        CC1 cc(g);
        if (cc.getCcCount() > 1) return;

        // Prim
        vector<bool> visited(g.getV(), false);
        // 选择顶点 0 作为切分的一部分
        visited[0] = true;
        // 进行 v - 1 次切分，每次切分得到最短的横切边
        for (int i = 0; i < g.getV() - 1; ++i) { // O(V)
            WeightedEdge minEdge(-1, -1, INT_MAX);
            for (int v = 0; v < g.getV(); ++v) { // O(V)
                if (visited[v]) {
                    for (int w : g.adj(v)) { // O(E)
                        // v-w 横切边 // 找到最小的横切边
                        if (!visited[w] && g.getWeight(v, w) < minEdge.weight) {
                            minEdge = WeightedEdge(v, w, g.getWeight(v, w));
                        }
                    }
                }
            }
            res.push_back(minEdge);

            // 扩展切分
            int v = minEdge.v;
            int w = minEdge.w;
            int newV = visited[v] ? w : v;
            visited[newV] = true;
        }
    }

    vector<WeightedEdge> getResult() {
        return res;
    }

};

int main() {
    WeightedAdjSet weightedAdjSet("C:/workspace/douma-algo/data/prim.txt");
    Prime prime(weightedAdjSet);
    vector<WeightedEdge> res = prime.getResult();
    for (int i = 0; i < res.size(); ++i) {
        std:cout << res[i].toString() << endl;
    }
    return 0;
}