# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class Leaderboard:
    def __init__(self):
        self.map = dict()


    """
    /**
     * 记录每个参赛者的分数
     * 逻辑：
     *      1. 假如参赛者已经在排行榜中，就给他的当前得分增加 score 分值并更新排行
     *      2. 假如参赛者不在排行榜中，就把他添加到排行榜，并将分数设置为 score
     * @param playerId  参赛者 Id，唯一标识一个参赛者
     * @param score 本次参赛者得分
     */
    """
    def addScore(self, playerId, score):
        if playerId in self.map:
            self.map[playerId] += score
        else:
            self.map[playerId] = score

    """
    /**
     * 返回前 k 名参赛者的得分总和
     * @param k
     * @return
     */
    """
    def top(self, k):
        # 1. 按照分数降序排序
        scores = [x for x in self.map.values()]
        scores.sort(reverse=True)

        # 2. 拿到前 k 名的分数，累加
        sum = 0
        for i in range(k):
            sum += scores[i]

        return sum

    # 将指定参赛者的成绩清零
    def reset(self, playerId):
        if playerId in self.map:
            del self.map[playerId]


if __name__ == '__main__':
    lb = Leaderboard()
    lb.addScore(1, 20)
    lb.addScore(2, 30)
    lb.addScore(3, 16)
    lb.addScore(4, 44)

    print(lb.top(2))