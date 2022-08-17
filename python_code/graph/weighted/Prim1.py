import heapq

from graph.weighted.WeightAdjSet import WeightAdjSet
from graph.dfs.CC1 import CC1


"""用优先队列优化"""
class Prim1:
    def __init__(self, g: WeightAdjSet):
        self.res = []
        MAX_INT = 2 ** 31 - 1

        # g 是连通图
        cc = CC1(g)
        if cc.getCcCount() > 1:
            return

        # Prim
        # 时间复杂度：O(E*logE)
        visited = [False] * g.getV()
        # 选择顶点 0 作为切分的一部分
        visited[0] = True

        # 小顶堆，以 weight 来比较
        pq = []
        for w in g.adj(0):
            # 将 (weight, v, w) push 到小顶堆
            heapq.heappush(pq, (g.getWeight(0, w), 0, w))
        while len(pq):
            # 1. 拿到最小横切边
            minEdge = heapq.heappop(pq)
            if visited[minEdge[1]] and visited[minEdge[2]]:
                # 不是横切边
                continue
            # 2. 加入到最小生成树中
            self.res.append(minEdge)
            # 3. 扩展切分
            newV = minEdge[2] if visited[minEdge[1]] else minEdge[1]
            visited[newV] = True
            # 将新的横切边放入到优先队列
            for w in g.adj(newV):
                if not visited[w]:
                    heapq.heappush(pq, (g.getWeight(newV, w), newV, w))

    def getRes(self):
        return self.res


if __name__ == '__main__':
    adjSet = WeightAdjSet("C:/workspace/douma-algo/data/prim.txt")
    prim = Prim1(adjSet)
    print(prim.getRes())
