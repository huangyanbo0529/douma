from graph.AdjSet import AdjSet
from graph.direct.GraphImpl import GraphImpl


class TopologySortDFS:
    def __init__(self, g: AdjSet):
        if g is None:
            return
        self.g = g
        self.isOnPath = [False] * self.g.getV()
        # self.visited 用于防止一个节点被重复访问
        self.visited = [False] * self.g.getV()
        self.hasCycle = False
        self.res = [0] * g.getV()
        self.index = len(self.res) - 1
        # 遍历图中每个顶点
        for v in range(self.g.getV()):
            # 先判断，没有遍历的顶点才能进行深度优先遍历
            if not self.visited[v]:
                self.dfs(v)

    # 时间复杂度：O(V)
    # 空间复杂度：O(V)
    # DFS 递归实现
    def dfs(self, v) -> bool:
        self.visited[v] = True
        self.isOnPath[v] = True
        for w in self.g.adj(v):
            if not self.visited[w]:
                if self.dfs(w):
                    return True
                # 否则，w 顶点已经被访问
                elif self.isOnPath[w]:
                    return True
        self.isOnPath[v] = False
        self.res[self.index] = v
        self.index -= 1

    def isHasCycle(self):
        return self.hasCycle

    def getRes(self):
        return self.res


if __name__ == '__main__':
    g = GraphImpl("C:/workspace/douma-algo/data/directedgraph-dfs.txt", True)
    dfs = TopologySortDFS(g)
    print(dfs.isHasCycle())
    print(dfs.getRes())
