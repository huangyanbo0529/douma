# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class ArraySet:
    def __init__(self):
        self.data = []

    def size(self):
        return len(self.data)

    def isEmpty(self):
        return len(self.data) == 0

    def add(self, e):
        if self.data.count(e) == 0:
            self.data.append(e)

    def remove(self, e):
        if self.data.count(e) > 0:
            self.data.remove(e)

    def contains(self, e):
        return self.data.count(e) > 0

    def toString(self):
        return "ArraySet[ data = {} ]".format(self.data)


if __name__ == '__main__':
    set1 = ArraySet()
    set1.add(2)
    set1.add(4)
    set1.add(1)

    print(set1.toString())

    set1.add(2)
    print(set1.toString())

    print(set1.contains(4))

    set1.remove(1)
    print(set1.toString())
