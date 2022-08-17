from graph.AdjSet import AdjSet


class BitpartitionDetection:
    def __init__(self, g: AdjSet):
        if g is None:
            return
        self.g = g
        # self.visited 用于防止一个节点被重复访问
        self.isBipartition, self.visited = True, [False] * self.g.getV()
        # -1 表示没有染颜色
        # 0 红色 1 蓝色
        self.colors = [-1] * self.g.getV()
        # 遍历图中每个顶点
        for v in range(self.g.getV()):
            # 先判断，没有遍历的顶点才能进行深度优先遍历
            if not self.visited[v]:
                if not self.dfs(v, 0):
                    self.isBipartition = False
                    break

    # 时间复杂度：O(V)
    # 空间复杂度：O(V)
    # DFS 递归实现
    def dfs(self, v, color) -> bool:
        self.visited[v] = True
        self.colors[v] = color
        for w in self.g.adj(v):
            if not self.visited[w]:
                # 如果 v 的颜色是 1，那么 w 的颜色就是 0
                # 如果 v 的颜色是 0，那么 w 的颜色就是 1
                if not self.dfs(w, 1 - color):
                    return False
            elif self.colors[w] == self.colors[v]:
                # 如果相邻顶点的颜色一样的话，则不是二分图
                return False
        return True

    def isBipartitionGraph(self):
        return self.isBipartition


if __name__ == '__main__':
    adjSet = AdjSet("C:/workspace/douma-algo/data/graph-dfs.txt")
    graphDFS = BitpartitionDetection(adjSet)
    print(graphDFS.isBipartitionGraph())
