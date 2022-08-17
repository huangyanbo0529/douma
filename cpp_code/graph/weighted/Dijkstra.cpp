/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <climits>
#include "WeightedAdjSet.cpp"

// 时间复杂度：O(V^2 * (1 + E))
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

        while (true) { // O(V)
            // 1. 找到当前没有访问的最短路径节点
            int currDis = INT_MAX;
            int curr = -1;
            for (int v = 0; v < g.getV(); ++v) { // O(V)
                if (!visited[v] && distance[v] < currDis) {
                    currDis = distance[v];
                    curr = v;
                }
            }
            if (curr == -1) break;

            // 2. 确认这个节点的最短路径就是当前大小
            visited[curr] = true;

            // 3. 根据这个节点的最短路径大小，更新其他节点的路径长度
            for (int w : g.adj(curr)) { // O(VE)
                if (!visited[w]) {
                    if (distance[curr] + g.getWeight(curr, w) < distance[w]) {
                        distance[w] = distance[curr] + g.getWeight(curr, w);
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