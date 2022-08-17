import heapq

from graph.weighted.WeightAdjSet import WeightAdjSet


# 时间复杂度：O(V * (logV + E))
class Dijkstra2:
    def __init__(self, g: WeightAdjSet, source: int):
        self.g = g
        self.source = source
        self.distance = [2**31 - 1] * g.getV()
        self.distance[source] = 0

        # 记录每个顶点的前一个顶点
        self.prevs = [-1] * g.getV()

        self.visited = [False] * g.getV()
        # 小顶堆，按照 dis 比较，所以 pq 中存储的是 (dis, v)
        pq = []
        heapq.heappush(pq, (0, source))
        while len(pq):
            # 1. 找到当前没有访问的最短路径节点
            curr = heapq.heappop(pq)[1]
            if self.visited[curr]:
                continue

            # 2. 确认这个节点的最短路径就是当前大小
            self.visited[curr] = True

            # 根据这个节点的最短路径大小，更新其他节点的路径长度
            for w in g.adj(curr):
                if not self.visited[w]:
                    if self.distance[curr] + g.getWeight(curr, w) < self.distance[w]:
                        self.distance[w] = self.distance[curr] + g.getWeight(curr, w)
                        heapq.heappush(pq, (self.distance[w], w))
                        self.prevs[w] = curr

    # 求 source 到 v 的最短路径
    def minDistanceTo(self, v):
        self.validateVertex(v)
        return self.distance[v]

    def isConnected(self, target):
        self.validateVertex(target)
        return self.visited[target]

    def validateVertex(self, v):
        if v < 0 or v >= self.g.getV():
            raise Exception("顶点 {} 不合格".format(v))

    def path(self, target):
        res = []
        # 1. 如果源顶点到不了目标顶点，直接返回
        if not self.isConnected(target):
            return res

        # 2. 根据 prevs 信息找到路径
        while target != self.source:
            res.append(target)
            target = self.prevs[target]
        res.append(self.source)

        # 3. 翻转
        res.reverse()

        return res

if __name__ == '__main__':
    g = WeightAdjSet("C:/workspace/douma-algo/data/Dijkstra.txt")
    dijkstra = Dijkstra2(g, 0)
    print(dijkstra.minDistanceTo(1))
    print(dijkstra.path(1))