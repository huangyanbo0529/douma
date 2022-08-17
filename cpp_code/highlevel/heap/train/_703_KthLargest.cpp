/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    // 小顶堆
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    // 时间复杂度：O(n)
    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};