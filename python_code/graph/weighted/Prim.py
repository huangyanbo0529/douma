from graph.weighted.WeightAdjSet import WeightAdjSet
from graph.dfs.CC1 import CC1


class Prim:
    def __init__(self, g: WeightAdjSet):
        self.res = []
        MAX_INT = 2 ** 31 - 1

        # g 是连通图
        cc = CC1(g)
        if cc.getCcCount() > 1:
            return

        # Prim 时间复杂度：O(V*V*E)
        visited = [False] * g.getV()
        # 选择顶点 0 作为切分的一部分
        visited[0] = True
        # 进行 v - 1 次切分，每次切分得到最短的横切边
        for i in range(g.getV() - 1):
            minEdge = (-1, -1, MAX_INT)
            for v in range(g.getV()):
                if visited[v]:
                    for w in g.adj(v):
                        # v-w 横切边 // 找到最小的横切边
                        if not visited[w] and g.getWeight(v, w) < minEdge[2]:
                            minEdge = (v, w, g.getWeight(v, w))
            self.res.append(minEdge)
            # 扩展切分
            v, w = minEdge[0], minEdge[1]
            newV = w if visited[v] else v
            visited[newV] = True

    def getRes(self):
        return self.res


if __name__ == '__main__':
    adjSet = WeightAdjSet("C:/workspace/douma-algo/data/prim.txt")
    prim = Prim(adjSet)
    print(prim.getRes())
