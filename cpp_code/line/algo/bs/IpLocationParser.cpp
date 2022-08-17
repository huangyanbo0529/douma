/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct IpLocation {
    long long startIp;
    long long endIp;
    string locationCity;

    IpLocation(long long startIp, long long endIp, string locationCity) {
        this->startIp = startIp;
        this->endIp = endIp;
        this->locationCity = locationCity;
    }
};

static bool ipLocationCompare(const IpLocation il1, const IpLocation il2) {
    if (il1.startIp < il2.startIp) {
        return true;
    }
    return false;
}

// c++ 没有内置的 split ，需要自己写一个
static void split(const string &s, vector<string> &v, const string &c) {
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (string::npos != pos2) {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}

static long long ip2Score(string ip) {
    vector<string> temps;
    split(ip, temps, ".");
    long long score = (long long)256 * 256 * 256 * atoi(temps[0].c_str())
                 + (long long)256 * 256 * atoi(temps[1].c_str())
                 + (long long)256 * atoi(temps[2].c_str())
                 + atoi(temps[3].c_str());
    return score;
}

class IpLocationParser {
public:
    vector<IpLocation> sortedIpLocations;

public:
    IpLocationParser() {
        // 1. 读取文件，解析 ip 地址段
        char c[300];
        ifstream inFile("C:/workspace/douma-algo/data/ip_location.txt", ios::in | ios::binary);

        while (inFile.getline(c, 300)) {
            string line = string(c);
            vector<string> temps;
            split(line, temps, " ");
            IpLocation ipLocation(ip2Score(temps[0]), ip2Score(temps[1]), temps[2]);
            sortedIpLocations.push_back(ipLocation);
        }

        // 2. 按照起始 ip 进行升序排列
        // 时间复杂度：O(nlogn)
        sort(sortedIpLocations.begin(), sortedIpLocations.end(), ipLocationCompare);
    }

    string getIpLocation(string ip) {
        long long score = ip2Score(ip);
        // 3. 在 sortedIpLocations 中找到最后一个 startIp 小于等于 score 的这个 ip 段
        int left = 0;
        int right = sortedIpLocations.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (score >= sortedIpLocations[mid].startIp) {
                if (mid == sortedIpLocations.size() - 1
                    || sortedIpLocations[mid + 1].startIp > score) {
                    if (score <= sortedIpLocations[mid].endIp) {
                        return sortedIpLocations[mid].locationCity;
                    } else {
                        // bug 修复：
                        // 如果查询的 ip > (mid 对应 ip 段的 startIp) 且 ip < (mid + 1 对应 ip 段的 startIp)，
                        // 但是如果 ip > (mid 对应 ip 段的 endIp)
                        // 说明 ip 超出了 mid 对应的 ip 段，又不属于 mid + 1 对应 ip 段直接退出即可
                        break;
                    }
                } else {
                    left = mid + 1;
                }
            } else { // target < nums[mid]
                right = mid - 1;
            }
        }
        return "";
    }
};

int main() {
    IpLocationParser parser;

    cout << parser.getIpLocation("202.101.49.1") << endl;


    return 0;
}