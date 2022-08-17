# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
from sortedcontainers import SortedSet
from operator import neg


class Player:
    def __init__(self, id, score):
        self.id = id
        self.score = score


def sort_key(player):
    return -player.score


class Leaderboard:
    def __init__(self):
        self.map = dict()
        self.players = SortedSet(key=sort_key)

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
            player = self.map[playerId]
            # 需要先从 SortedSet 中删除
            # 等重新计算完 score 后再添加到 SortedSet 中
            # 因为这个 player 需要重新排序，而只有调用 SortedSet 的 add 方法，才能重新排序
            self.players.remove(player)
            player.score += score
        else:
            player = Player(playerId, score)
            self.map[playerId] = player
        self.players.add(player)

    """
    /**
     * 返回前 k 名参赛者的得分总和
     * @param k
     * @return
     */
    """
    def top(self, k):
        sum = 0
        for p in self.players:
            if k == 0:
                break
            sum, k = sum + p.score, k - 1
        return sum

    # 将指定参赛者的成绩清零
    def reset(self, playerId):
        if playerId in self.map:
            self.players.remove(self.map[playerId])
            del self.map[playerId]


if __name__ == '__main__':
    lb = Leaderboard()
    lb.addScore(1, 20)
    lb.addScore(2, 30)
    lb.addScore(3, 16)
    lb.addScore(4, 44)

    print(lb.top(2))