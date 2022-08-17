from collections import deque

from graph.AdjSet import AdjSet


class CC:
    def __init__(self, g: AdjSet):
        if g is None:
            return
        self.g = g
        self.ccCount = 0
        self.visited = [-1] * self.g.getV()
        for v in range(self.g.getV()):
            if self.visited[v] == -1:
                self.ccCount += 1
                self.bfs(v, self.ccCount)

    def bfs(self, v, ccId):
        if self.g is None:
            return
        queue = deque()
        queue.append(v)
        # 维护节点所属的连通分量
        self.visited[v] = ccId
        while len(queue):
            curr = queue.popleft()
            for w in self.g.adj(curr):
                if self.visited[w] == -1:
                    queue.append(w)
                    # 维护节点所属的连通分量
                    self.visited[w] = ccId

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
    g = AdjSet("C:/workspace/douma-algo/data/graph-bfs.txt")
    cc = CC(g)
    print(cc.getCcCount())
