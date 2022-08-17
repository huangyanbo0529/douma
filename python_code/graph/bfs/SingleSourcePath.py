from collections import deque

from graph.AdjSet import AdjSet


class SingleSourcePath:
    def __init__(self, g: AdjSet, source: int):
        if g is None:
            return
        self.g = g
        self.source = source
        self.prevs = [-1] * self.g.getV()
        self.visited = [False] * self.g.getV()
        self.bfs(source)

    def bfs(self, v):
        if self.g is None:
            return
        queue = deque()
        queue.append(v)
        self.visited[v] = True
        # 维护顶点的前一个顶点
        self.prevs[v] = v
        while len(queue):
            curr = queue.popleft()
            for w in self.g.adj(curr):
                if not self.visited[w]:
                    queue.append(w)
                    self.visited[w] = True
                    # 维护顶点的前一个顶点
                    self.prevs[w] = curr

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
    g = AdjSet("C:/workspace/douma-algo/data/graph-bfs.txt")
    graphBFS = SingleSourcePath(g, 0)
    print(graphBFS.path(6))
