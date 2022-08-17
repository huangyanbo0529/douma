from collections import deque

from graph.direct.GraphImpl import GraphImpl


class TopologySortBFS:
    def __init__(self, g: GraphImpl):
        if not g.isDirectedGraph():
            raise Exception("只能对有向图进行拓扑排序")

        self.hasCycle = False
        indegrees = [0] * g.getV()
        for v in range(g.getV()):
            indegrees[v] = g.indegree(v)

        queue = deque()
        for v in range(g.getV()):
            if indegrees[v] == 0:
                queue.append(v)

        self.res = [0] * g.getV()
        index = 0
        while len(queue):
            v = queue.popleft()
            self.res[index] = v
            index += 1
            for w in g.adj(v):
                indegrees[w] -= 1
                if indegrees[w] == 0:
                    queue.append(w)

        if index != g.getV():
            self.hasCycle = True

    def isHasCycle(self):
        return self.hasCycle

    def getRes(self):
        return self.res

if __name__ == '__main__':
    g = GraphImpl("C:/workspace/douma-algo/data/directedgraph-dfs.txt", True)
    bfs = TopologySortBFS(g)
    print(bfs.isHasCycle())
    print(bfs.getRes())