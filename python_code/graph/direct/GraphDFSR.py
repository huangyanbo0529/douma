from graph.AdjSet import AdjSet
from graph.direct.GraphImpl import GraphImpl


class GraphDFSR:
    def __init__(self, g: AdjSet):
        if g is None:
            return
        self.g = g
        # self.visited 用于防止一个节点被重复访问
        self.res, self.visited = [], [False] * self.g.getV()
        # 遍历图中每个顶点
        for v in range(self.g.getV()):
            # 先判断，没有遍历的顶点才能进行深度优先遍历
            if not self.visited[v]:
                self.dfs(v)

    # 时间复杂度：O(V)
    # 空间复杂度：O(V)
    # DFS 递归实现
    def dfs(self, v):
        self.res.append(v)
        self.visited[v] = True
        for w in self.g.adj(v):
            if not self.visited[w]:
                self.dfs(w)

    def getRes(self):
        return self.res


if __name__ == '__main__':
    adjSet = GraphImpl("C:/workspace/douma-algo/data/directedgraph-dfs.txt", True)
    graphDFS = GraphDFSR(adjSet)
    print(graphDFS.getRes())
