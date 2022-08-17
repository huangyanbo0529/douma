from collections import deque

from graph.AdjSet import AdjSet


class BipartitionDetection:
    def __init__(self, g: AdjSet):
        if g is None:
            return
        self.g = g
        # -1 表示没有染颜色 0 红色 1 蓝色
        self.colors = [-1] * self.g.getV()
        self.isBipartition = True
        self.visited = [False] * self.g.getV()
        for v in range(self.g.getV()):
            if not self.visited[v]:
                self.bfs(v)

    def bfs(self, v):
        if self.g is None:
            return True
        queue = deque()
        queue.append(v)
        self.visited[v] = True
        self.colors[v] = 0
        while len(queue):
            curr = queue.popleft()
            for w in self.g.adj(curr):
                # 如果 w 没有遍历过，则需要染色
                if not self.visited[w]:
                    queue.append(w)
                    self.visited[w] = True
                    # 给顶点 w 染色，和 curr 的颜色不一样
                    self.colors[w] = 1 - self.colors[curr]
                elif self.colors[w] == self.colors[curr]:
                    # 如果 w 被访问过，并且它的颜色和相邻点一样
                    # 那么可以判定不是二分图
                    return False
        return True

    def getIsBipartition(self):
        return self.isBipartition


if __name__ == '__main__':
    g = AdjSet("C:/workspace/douma-algo/data/graph-bfs.txt")
    graphBFS = BipartitionDetection(g)
    print(graphBFS.getIsBipartition())
