# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class BitMap:
    def __init__(self, nBits):
        self.nBits = nBits
        self.bytes = [0] * (nBits // 8 + 1)

    def set(self, num):
        if num > self.nBits:
            return
        # 找到第几个字节
        byteIndex = num // 8
        # 找到第几位
        bitIndex = num % 8
        self.bytes[byteIndex] |= (1 << bitIndex)

    def contains(self, target):
        if target > self.nBits:
            return False
        # 找到第几个字节
        byteIndex = target // 8
        # 找到第几位
        bitIndex = target % 8
        return ((1 << bitIndex) & self.bytes[byteIndex]) != 0


if __name__ == '__main__':
    data = [2, 7, 2, 5, 3]
    target = 2
    bitmap = BitMap(8)
    for i in range(len(data)):
        bitmap.set(data[i])

    if bitmap.contains(target):
        print("存在目标 {}".format(target))