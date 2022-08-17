/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <climits>
#include <queue>
#include "WeightedAdjSet.cpp"

struct Pair {
    int v;
    int dis;

    Pair(int v, int dis): v(v), dis(dis) {}
};

static bool comparePair(Pair p1, Pair p2) {
    if (p1.dis > p2.dis) {
        return true;
    }
    return false;
}

// 时间复杂度：O(V * (logV + V * E))
class Dijkstra {
private:
    WeightedAdjSet g;
    vector<int> distance;
    vector<bool> visited;

    void validateVertex(int v) {
        if (v < 0 || v >= g.getV()) {
            throw "顶点 " + to_string(v) + " 不合格";
        }
    }

public:
    Dijkstra(WeightedAdjSet g, int source): g(g) {
        distance.resize(g.getV());
        fill(distance.begin(),  distance.end(), INT_MAX);

        visited.resize(g.getV());
        fill(visited.begin(),  visited.end(), false);

        distance[source] = 0;

        // 小顶堆
        priority_queue<Pair, vector<Pair>, decltype(&comparePair)> pq(comparePair);
        pq.push(Pair(source, 0));
        while (!pq.empty()) { // O(V)
            // 1. 找到当前没有访问的最短路径节点
            int curr = pq.top().v;
            pq.pop(); // O(logV)
            if (visited[curr]) continue;

            // 2. 确认这个节点的最短路径就是当前大小
            visited[curr] = true;

            // 3. 根据这个节点的最短路径大小，更新其他节点的路径长度
            for (int w : g.adj(curr)) { // O(V*E)
                if (!visited[w]) {
                    if (distance[curr] + g.getWeight(curr, w) < distance[w]) {
                        distance[w] = distance[curr] + g.getWeight(curr, w);
                        pq.push(Pair(w, distance[w]));
                    }
                }
            }
        }
    }

    int minDistanceTo(int v) {
        validateVertex(v);
        return distance[v];
    }
};

int main() {
    WeightedAdjSet weightedAdjSet("C:/workspace/douma-algo/data/Dijkstra.txt");
    Dijkstra dijkstra(weightedAdjSet, 0);
    cout << to_string(dijkstra.minDistanceTo(1)) << endl;
    return 0;
}