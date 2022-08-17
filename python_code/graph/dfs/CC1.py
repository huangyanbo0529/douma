from graph.Graph import Graph
from graph.AdjSet import AdjSet


# 求图的连通分量
class CC1:
    def __init__(self, g: Graph):
        if g is None:
            return
        self.g = g
        # self.visited 用于防止一个节点被重复访问
        self.ccCount, self.visited = 0, [-1] * self.g.getV()
        # 遍历图中每个顶点
        for v in range(self.g.getV()):
            # 先判断，没有遍历的顶点才能进行深度优先遍历
            if self.visited[v] == -1:
                self.ccCount += 1
                self.dfs(v, self.ccCount)

    # 时间复杂度：O(V)
    # 空间复杂度：O(V)
    # DFS 递归实现
    def dfs(self, v, ccId):
        self.visited[v] = ccId
        for w in self.g.adj(v):
            if self.visited[w] == -1:
                self.dfs(w, ccId)

    def getCcCount(self):
        return self.ccCount

    def components(self):
        res = [0] * self.ccCount
        for i in range(self.ccCount):
            res[i] = []
        for v in range(self.g.getV()):
            cc = self.visited[v]
            res[cc - 1].append(v)
        return res

    def isConnected(self, v, w):
        self.validateVertex(v)
        self.validateVertex(w)
        return self.visited[v] == self.visited[w]

    def validateVertex(self, v):
        if v < 0 or v >= self.g.getV():
            raise Exception("顶点 {} 不合格".format(v))


if __name__ == '__main__':
    adjSet = AdjSet("C:/workspace/douma-algo/data/graph-dfs.txt")
    cc = CC1(adjSet)
    print(cc.getCcCount())
    print(cc.components())
    print(cc.isConnected(0, 6))
