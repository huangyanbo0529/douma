from graph.Graph import Graph


# 邻接矩阵
# 空间复杂度：O(V^2)，浪费空间
class AdjMatrix(Graph):

    # 建图时间复杂度：O(E)
    def __init__(self, fileName):
        with open(fileName, 'r') as reader:
            lines = reader.readlines()
        arr = lines[0].split(" ")
        # 初始化顶点的个数，以及边的个数
        self.V, self.E = int(arr[0]), int(arr[1])
        # 初始化邻接矩阵
        self.__adj = [[0] * self.V for _ in range(self.V)]
        for i in range(1, len(lines)):
            arr = lines[i].split(" ")
            a, b = int(arr[0]), int(arr[1])
            self.validateVertex(a)
            self.validateVertex(b)
            # 检测自环边
            if a == b:
                raise Exception("出现了自环边，错误")
            # 检测平行边
            if self.__adj[a][b] == 1:
                raise Exception("出现了平行边，错误")
            self.__adj[a][b] = 1
            self.__adj[b][a] = 1

    def validateVertex(self, v):
        if v < 0 or v >= self.V:
            raise Exception("顶点 {} 不合格".format(v))

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
        return self.__adj[v][w] == 1

    # 获取指定顶点所有相邻的顶点
    # 时间复杂度：O(V)
    def adj(self, v: int):
        self.validateVertex(v)
        res = []
        for i in range(self.V):
            if self.__adj[v][i] == 1:
                res.append(i)
        return res

    # 获取指定顶点的度数
    def degree(self, v: int):
        return len(self.adj(v))

    # 返回邻接矩阵字符串
    def toString(self):
        res = "顶点数 = {}，边数 = {} \n".format(self.V, self.E)
        for i in range(self.V):
            for j in range(self.V):
                res += str(self.__adj[i][j]) + " "
            res += "\n"
        return res


# 测试
adjMatrix = AdjMatrix("C:/workspace/douma-algo/data/graph.txt")
print(adjMatrix.toString())
print(adjMatrix.degree(1))
