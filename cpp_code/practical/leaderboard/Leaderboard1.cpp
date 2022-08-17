/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    int id;
    int scores;

    Player(int id, int scores): id(id), scores(scores) {}
};

static bool comparePlayer(Player* p1, Player* p2) {
    if (p1->scores == p2->scores) {
        return p1->id < p2->id;
    } else {
        return p2->scores < p1->scores;
    }
}

class Leaderboard {
private:
    unordered_map<int, Player*> map;
    set<Player*, decltype(&comparePlayer)> players;


public:
    Leaderboard(){
        players = set<Player*, decltype(&comparePlayer)>(comparePlayer);
    }

    /**
     * 记录每个参赛者的分数
     * 逻辑：
     *      1. 假如参赛者已经在排行榜中，就给他的当前得分增加 score 分值并更新排行
     *      2. 假如参赛者不在排行榜中，就把他添加到排行榜，并将分数设置为 score
     * @param playerId  参赛者 Id，唯一标识一个参赛者
     * @param score 本次参赛者得分
     */
    void addScore(int playerId, int score) {
        Player* player = nullptr;
        if (map.count(playerId)) {
            player = map[playerId];
            // 需要先从 TreeSet 中删除
            // 等重新计算完 score 后再添加到 TreeSet 中
            // 因为这个 player 需要重新排序，而只有调用 TreeSet 的 add 方法，才能重新排序
            players.erase(player);
            player->scores += score;
        } else {
            player = new Player(playerId, score);
            map[playerId] = player;
        }
        players.insert(player);
    }

    /**
     * 返回前 k 名参赛者的得分总和
     * @param k
     * @return
     */
    int top(int k) {
        int sum = 0;
        set<Player*>::iterator iter = players.begin();
        while (iter != players.end() && k > 0) {
            sum += (*iter)->scores;
            k--;
            iter++;
        }
        return sum;
    }

    /**
     * 将指定参赛者的成绩清零
     * @param playerId
     */
    void reset(int playerId) {
        if (map.count(playerId)) {
            players.erase(map[playerId]);
            map.erase(playerId);
        }
    }

};

int main() {
    Leaderboard leaderboard;
    leaderboard.addScore(1, 20);
    leaderboard.addScore(2, 30);
    leaderboard.addScore(3, 16);
    leaderboard.addScore(4, 44);

    std::cout << leaderboard.top(1) << endl;

    return 0;
}