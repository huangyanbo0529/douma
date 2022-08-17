/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (!intervals.size()) return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> outputs;
        outputs.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& lastInterval = outputs.back();
            int currLeft = intervals[i][0];
            int currRight = intervals[i][1];
            if (lastInterval[1] < currLeft) {
                outputs.push_back(intervals[i]);
            } else {
                lastInterval[1] = max(lastInterval[1], currRight);
            }
        }

        return outputs;
    }
};