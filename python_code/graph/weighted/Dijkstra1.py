import heapq

from graph.weighted.WeightAdjSet import WeightAdjSet


# 时间复杂度：O(V * (logV + E))
class Dijkstra1:
    def __init__(self, g: WeightAdjSet, source: int):
        self.g = g
        self.distance = [2**31 - 1] * g.getV()
        self.distance[source] = 0

        visited = [False] * g.getV()
        # 小顶堆，按照 dis 比较，所以 pq 中存储的是 (dis, v)
        pq = []
        heapq.heappush(pq, (0, source))
        while len(pq):
            # 1. 找到当前没有访问的最短路径节点
            curr = heapq.heappop(pq)[1]
            if visited[curr]:
                continue

            # 2. 确认这个节点的最短路径就是当前大小
            visited[curr] = True

            # 根据这个节点的最短路径大小，更新其他节点的路径长度
            for w in g.adj(curr):
                if not visited[w]:
                    if self.distance[curr] + g.getWeight(curr, w) < self.distance[w]:
                        self.distance[w] = self.distance[curr] + g.getWeight(curr, w)
                        heapq.heappush(pq, (self.distance[w], w))

    # 求 source 到 v 的最短路径
    def minDistanceTo(self, v):
        self.validateVertex(v)
        return self.distance[v]

    def validateVertex(self, v):
        if v < 0 or v >= self.g.getV():
            raise Exception("顶点 {} 不合格".format(v))


if __name__ == '__main__':
    g = WeightAdjSet("C:/workspace/douma-algo/data/Dijkstra.txt")
    dijkstra = Dijkstra1(g, 0)
    print(dijkstra.minDistanceTo(1))