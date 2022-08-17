/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <queue>

using namespace std;


// 3. 大顶堆 + 小顶堆
class MedianFinder3 {
public:
    // 小顶堆
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // 大顶堆
    priority_queue<int> maxHeap;

    /** initialize your data structure here. */
    MedianFinder3() {

    }

    // 时间复杂度：O(logn)
    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }

        if (num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) * 0.5;
        }
    }
};