from collections import deque

from graph.AdjSet import AdjSet


class SingleSourcePath1:
    def __init__(self, g: AdjSet, source: int, target: int):
        if g is None:
            return
        self.g = g
        self.source = source
        self.target = target
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
            if curr == self.target:
                return
            for w in self.g.adj(curr):
                if not self.visited[w]:
                    queue.append(w)
                    self.visited[w] = True
                    # 维护顶点的前一个顶点
                    self.prevs[w] = curr

    def isConnected(self):
        self.validateVertex(self.target)
        return self.visited[self.target]

    def validateVertex(self, v):
        if v < 0 or v >= self.g.getV():
            raise Exception("顶点 {} 不合格".format(v))

    def path(self):
        res = []
        # 1. 如果源顶点到不了目标顶点，直接返回
        if not self.isConnected():
            return res

        # 2. 根据 prevs 信息找到路径
        tmp = self.target
        while tmp != self.source:
            res.append(tmp)
            tmp = self.prevs[tmp]
        res.append(self.source)

        # 3. 翻转
        res.reverse()

        return res


if __name__ == '__main__':
    g = AdjSet("C:/workspace/douma-algo/data/graph-bfs.txt")
    graphBFS = SingleSourcePath1(g, 0, 6)
    print(graphBFS.path())
