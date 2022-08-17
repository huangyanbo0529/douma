/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <string>
#include <unordered_map>

using namespace std;

using Start = pair <string, int>;
using StartEnd = pair <string, string>;
using SumAndAmount = pair <int, int>;

struct StartEndHash {
    int operator() (const StartEnd& x) const{
        return hash <string> () (x.first + x.second);
    }
};


class UndergroundSystem {
private:
    // 维护每个乘客的起始站信息
    unordered_map<int, Start> startInfo;
    // 维护两个站的乘客信息：所有的乘客数，以及所有乘客花的时间
    unordered_map<StartEnd, SumAndAmount, StartEndHash> table;

public:
    // 编号为 id 的乘客在 t 时刻进入地铁站 stationName
    void checkIn(int id, string stationName, int t) {
        startInfo[id] = Start(stationName, t);
    }

    // 编号为 id 的乘客在 t 时刻离开地铁站 stationName
    void checkOut(int id, string stationName, int t) {
        // 拿到起始点信息
        Start start = startInfo[id];

        // 计算花费的时间
        StartEnd key = StartEnd(start.first, stationName);
        SumAndAmount sumAmount = table.count(key) ? table[key] : SumAndAmount(0, 0);
        sumAmount.first += (t - start.second);
        sumAmount.second += 1;

        table[key] = sumAmount;
    }

    // 返回地铁站 startStation 到地铁站 endStation 的平均花费时间
    double getAverageTime(string startStation, string endStation) {
        StartEnd key = StartEnd(startStation, endStation);
        SumAndAmount sumAmount = table[key];
        return 1.0 * sumAmount.first / sumAmount.second;
    }
};