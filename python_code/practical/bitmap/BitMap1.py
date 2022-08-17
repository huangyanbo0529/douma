# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class BitMap:
    def __init__(self):
        self.b = 0

    def set(self, num):
        """
        set 2
            00000001 << 2
            00000100
          | 00000000
          = 00000100

            set 2
            00000001 << 2
            00000100
          | 00000100
          = 00000100
        :param num:
        :return:
        """
        self.b |= (1 << num)

    def contains(self, target):
        """
        contains 4
            00000001 << 4
            00010000
          & 10101100
          = 00000000
        :param target:
        :return:
        """
        # 10101100
        return ((1 << target) & self.b) != 0

    def toString(self):
        return "BitMap[ b = {} ]".format(bin(self.b))


if __name__ == '__main__':
    data = [2, 7, 2, 5, 3]
    target = 2
    bitmap = BitMap()
    for i in range(len(data)):
        bitmap.set(data[i])

    print(bitmap.toString())

    if bitmap.contains(target):
        print("存在目标 {}".format(target))