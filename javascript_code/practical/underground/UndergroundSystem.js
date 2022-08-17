// 抖码算法，让算法学习变的简单有趣
// 作者：老汤


var UndergroundSystem = function() {
    this.startInfo = new Map()
    this.table = new Map()
};

/**
 * @param {number} id
 * @param {string} stationName
 * @param {number} t
 * @return {void}
 */
UndergroundSystem.prototype.checkIn = function(id, stationName, t) {
    const startObj = {
        "station": stationName,
        "time": t
    }
    this.startInfo.set(id, startObj)
};

/**
 * @param {number} id
 * @param {string} stationName
 * @param {number} t
 * @return {void}
 */
UndergroundSystem.prototype.checkOut = function(id, stationName, t) {
    // 拿到起点的信息
    const startObj = this.startInfo.get(id)

    // 计算花费的时间
    const key = `${startObj.station}-${stationName}`
    // 这里 sumAmount 是一个包含两个元素的数组
    // 第一个元素表示的是总时间，第二个元素表示的是乘客总数
    const sumAmount = this.table.has(key) ? this.table.get(key) : [0, 0]

    sumAmount[0] += (t - startObj.time) // 总时间
    sumAmount[1] += 1   // 乘客总数

    this.table.set(key, sumAmount)
};

/**
 * @param {string} startStation
 * @param {string} endStation
 * @return {number}
 */
UndergroundSystem.prototype.getAverageTime = function(startStation, endStation) {
    const key = `${startStation}-${endStation}`
    const sumAmount = this.table.get(key)
    return sumAmount[0] / sumAmount[1]
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * var obj = new UndergroundSystem()
 * obj.checkIn(id,stationName,t)
 * obj.checkOut(id,stationName,t)
 * var param_3 = obj.getAverageTime(startStation,endStation)
 */