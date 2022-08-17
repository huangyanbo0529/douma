# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class Start:
    def __init__(self, station, time):
        self.station = station
        self.time = time


class SumAmount:
    def __init__(self, sum, amount):
        self.sum = sum
        self.amount = amount


class UndergroundSystem:
    def __init__(self):
        # 维护每个乘客的起始站信息
        self.startInfo = dict()
        # 维护两个站的乘客信息：所有的乘客数，以及所有乘客花的时间
        self.table = dict()

    # 编号为 id 的乘客在 t 时刻进入地铁站 stationName
    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.startInfo[id] = Start(stationName, t)

    # 编号为 id 的乘客在 t 时刻离开地铁站 stationName
    def checkOut(self, id: int, stationName: str, t: int) -> None:
        start = self.startInfo[id]
        # 计算花费的时间
        key = "{}-{}".format(start.station, stationName)
        sumAmount = self.table[key] if key in self.table else SumAmount(0, 0)
        sumAmount.sum += (t - start.time)
        sumAmount.amount += 1
        self.table[key] = sumAmount

    # 返回地铁站 startStation 到地铁站 endStation 的平均花费时间
    def getAverageTime(self, startStation: str, endStation: str) -> float:
        key = "{}-{}".format(startStation, endStation)
        sumAmount = self.table[key]
        return sumAmount.sum / sumAmount.amount