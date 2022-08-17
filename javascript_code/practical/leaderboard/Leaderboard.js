// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


// 以下 js 格式和 leetcode 保持一致
var Leaderboard = function() {
    this.map = new Map()
};

/**
 * @param {number} playerId
 * @param {number} score
 * @return {void}
 */
Leaderboard.prototype.addScore = function(playerId, score) {
    if (this.map.has(playerId)) {
        this.map.set(playerId, this.map.get(playerId) + score)
    } else {
        this.map.set(playerId, score)
    }
};

/**
 * @param {number} K
 * @return {number}
 */
Leaderboard.prototype.top = function(K) {
    // 1. 按照分数降序排序
    const scores = Array.from(this.map.values()).sort((a, b) => b - a)

    // 2. 拿到前 k 名的分数，累加
    // O(k)
    let sum = 0;
    for (let i = 0; i < K; i++) {
        sum += scores[i];
    }

    return sum;
};

/**
 * @param {number} playerId
 * @return {void}
 */
Leaderboard.prototype.reset = function(playerId) {
    if (this.map.has(playerId)) {
        this.map.delete(playerId)
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * var obj = new Leaderboard()
 * obj.addScore(playerId,score)
 * var param_2 = obj.top(K)
 * obj.reset(playerId)
 */