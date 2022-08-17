from graph.Graph import Graph


# 邻接表
# 空间复杂度：O(V + E)
# 支持无向无权图和有向无权图
class GraphImpl(Graph):

    # 建图时间复杂度：O(E)
    def __init__(self, fileName, isDirected):
        self.isDirected = isDirected
        with open(fileName, 'r') as reader:
            lines = reader.readlines()
        arr = lines[0].split(" ")
        # 初始化顶点的个数，以及边的个数
        self.V, self.E = int(arr[0]), int(arr[1])
        # 初始化邻接表，因为 python 中没有内置的链表，所以我们这边直接使用 set 来存储
        self.adjSets = [0] * self.V
        for i in range(self.V):
            self.adjSets[i] = set()
        self.indegrees = [0] * self.V
        self.outdegrees = [0] * self.V
        for i in range(1, len(lines)):
            arr = lines[i].split(" ")
            a, b = int(arr[0]), int(arr[1])
            self.validateVertex(a)
            self.validateVertex(b)
            # 检测自环边
            if a == b:
                raise Exception("出现了自环边，错误")
            # 检测平行边
            # O(1)
            if b in self.adjSets[a]:
                raise Exception("出现了平行边，错误")

            self.adjSets[a].add(b)

            # 如果是有向图的话，统计顶点的出度和入度
            if isDirected:
                self.outdegrees[a] += 1
                self.indegrees[b] += 1
            if not isDirected:
                self.adjSets[b].add(a)

    def validateVertex(self, v):
        if v < 0 or v >= self.V:
            raise Exception("顶点 {} 不合格".format(v))

    def isDirectedGraph(self):
        return self.isDirected

    # 获取图的边数
    def getE(self):
        return self.E

    # 获取图的顶点数
    def getV(self):
        return self.V

    # 判断两个指定的顶点之间是否有边
    # 时间复杂度：O(1)
    def hasEdge(self, v: int, w: int):
        self.validateVertex(v)
        self.validateVertex(w)
        return w in self.adjSets[v]

    # 获取指定顶点所有相邻的顶点
    # 时间复杂度：O(1)
    def adj(self, v: int):
        self.validateVertex(v)
        return self.adjSets[v]

    # 获取指定顶点的度数
    def degree(self, v: int):
        if self.isDirected:
            raise Exception("只有无向图才可以计算顶点的度数")
        return len(self.adj(v))

    def indegree(self, v):
        if not self.isDirected:
            raise Exception("只有有向图才可以计算顶点的入度")
        self.validateVertex(v)
        return self.indegrees[v]

    def outdegree(self, v):
        if not self.isDirected:
            raise Exception("只有有向图才可以计算顶点的出度")
        self.validateVertex(v)
        return self.outdegrees[v]

    # 返回邻接矩阵字符串
    def toString(self):
        res = "顶点数 = {}，边数 = {}，isDirected = {} \n".format(self.V, self.E, self.isDirected)
        for v in range(self.V):
            res += str(v) + ": "
            for w in self.adjSets[v]:
                res += str(w) + " "
            res += "\n"
        return res


if __name__ == '__main__':
    # 测试
    adjSet = GraphImpl("C:/workspace/douma-algo/data/graph.txt", True)
    print(adjSet.toString())