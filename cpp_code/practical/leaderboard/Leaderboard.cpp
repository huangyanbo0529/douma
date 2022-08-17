/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Leaderboard {
private:
    unordered_map<int, int> map;

public:
    Leaderboard(){}

    /**
     * 记录每个参赛者的分数
     * 逻辑：
     *      1. 假如参赛者已经在排行榜中，就给他的当前得分增加 score 分值并更新排行
     *      2. 假如参赛者不在排行榜中，就把他添加到排行榜，并将分数设置为 score
     * @param playerId  参赛者 Id，唯一标识一个参赛者
     * @param score 本次参赛者得分
     */
    void addScore(int playerId, int score) {
        if (map.count(playerId)) {
            map[playerId] += score;
        } else {
            map[playerId] = score;
        }
    }

    /**
     * 返回前 k 名参赛者的得分总和
     * @param k
     * @return
     */
    int top(int k) {
        // 1. 按照分数降序排序
        vector<int> scores;
        for (auto& kv : map) scores.push_back(kv.second);
        // O(nlogn) - 性能瓶颈
        sort(scores.begin(),  scores.end(), greater<int>());

        // 2. 拿到前 k 名的分数，累加
        // O(k)
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += scores[i];
        }

        return sum;
    }

    /**
     * 将指定参赛者的成绩清零
     * @param playerId
     */
    void reset(int playerId) {
        if (map.count(playerId)) {
            map.erase(playerId);
        }
    }

};