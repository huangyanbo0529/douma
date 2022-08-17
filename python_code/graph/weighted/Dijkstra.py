from graph.weighted.WeightAdjSet import WeightAdjSet


# 时间复杂度：O(V * (V + E))
class Dijkstra:
    def __init__(self, g: WeightAdjSet, source: int):
        self.g = g
        self.distance = [2**31 - 1] * g.getV()
        self.distance[source] = 0

        visited = [False] * g.getV()

        while True:
            # 1. 找到当前没有访问的最短路径节点
            curr, curDis = -1, 2**31 - 1
            for v in range(g.getV()):
                if not visited[v] and self.distance[v] < curDis:
                    curDis = self.distance[v]
                    curr = v
            if curr == -1:
                break

            # 2. 确认这个节点的最短路径就是当前大小
            visited[curr] = True

            # 3. 根据这个节点的最短路径大小，更新其他节点的路径长度
            for w in g.adj(curr):
                if not visited[w]:
                    if self.distance[curr] + g.getWeight(curr, w) < self.distance[w]:
                        self.distance[w] = self.distance[curr] + g.getWeight(curr, w)

    # 求 source 到 v 的最短路径
    def minDistanceTo(self, v):
        self.validateVertex(v)
        return self.distance[v]

    def validateVertex(self, v):
        if v < 0 or v >= self.g.getV():
            raise Exception("顶点 {} 不合格".format(v))


if __name__ == '__main__':
    g = WeightAdjSet("C:/workspace/douma-algo/data/Dijkstra.txt")
    dijkstra = Dijkstra(g, 0)
    print(dijkstra.minDistanceTo(1))