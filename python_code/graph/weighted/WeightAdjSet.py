from graph.Graph import Graph


# 邻接表
# 空间复杂度：O(V + E)
class WeightAdjSet(Graph):

    # 建图时间复杂度：O(E)
    def __init__(self, fileName):
        with open(fileName, 'r') as reader:
            lines = reader.readlines()
        arr = lines[0].split(" ")
        # 初始化顶点的个数，以及边的个数
        self.V, self.E = int(arr[0]), int(arr[1])
        # 初始化邻接表，因为 python 中没有内置的链表，所以我们这边直接使用 set 来存储
        self.adjSets = [0] * self.V
        for i in range(self.V):
            self.adjSets[i] = dict()
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
            if b in self.adjSets[a].keys():
                raise Exception("出现了平行边，错误")
            weight = int(arr[2])
            self.adjSets[a][b] = weight
            self.adjSets[b][a] = weight

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
        return w in self.adjSets[v].keys()

    # 获取指定边的权重值
    def getWeight(self, v, w):
        if self.hasEdge(v, w):
            return self.adjSets[v][w]
        return -1

    # 获取指定顶点所有相邻的顶点
    # 时间复杂度：O(1)
    def adj(self, v: int):
        self.validateVertex(v)
        return self.adjSets[v].keys()

    # 获取指定顶点的度数
    def degree(self, v: int):
        return len(self.adjSets(v))

    # 返回邻接矩阵字符串
    def toString(self):
        res = "顶点数 = {}，边数 = {} \n".format(self.V, self.E)
        for v in range(self.V):
            res += str(v) + ": "
            adjMap = self.adjSets[v]
            for w in adjMap.keys():
                res += "(" + str(w) + ", " + str(adjMap[w]) + ")"
            res += "\n"
        return res


if __name__ == '__main__':
    # 测试
    adjSet = WeightAdjSet("C:/workspace/douma-algo/data/weighted-graph.txt")
    print(adjSet.toString())
