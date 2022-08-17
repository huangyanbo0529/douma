from abc import abstractmethod, ABCMeta


class Graph(metaclass=ABCMeta):

    # 获取图的边数
    @abstractmethod
    def getE(self):
        pass

    # 获取图的顶点数
    @abstractmethod
    def getV(self):
        pass

    # 判断两个指定的顶点之间是否有边
    @abstractmethod
    def hasEdge(self, v: int, w: int):
        pass

    # 获取指定顶点所有相邻的顶点
    @abstractmethod
    def adj(self, v: int):
        pass

    # 获取指定顶点的度数
    @abstractmethod
    def degree(self, v: int):
        pass

    # 返回图的字符串形式
    @abstractmethod
    def toString(self):
        pass
