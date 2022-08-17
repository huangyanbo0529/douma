/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <iostream>
#include <sstream>
#include <queue>
#include "./PriorityQueue.cpp"

using namespace std;

bool compare_int(int x, int y) {
    return x < y;
}

int main() {

    // 大顶堆
    PriorityQueue<int, greater<int>> pq;

    // 小顶堆
    // PriorityQueue<int, less<int>> pq;

    // 自定义
    // PriorityQueue<int, decltype(&compare_int)> pq(compare_int);

    pq.enqueue(13);
    pq.enqueue(10);
    pq.enqueue(56);

    cout << to_string(pq.dequeue()) << endl;
    cout << to_string(pq.dequeue()) << endl;

    // c++ 内置的优先队列，需要先 #include <queue> ，默认是大顶堆
    // priority_queue<int> cppPQ;

    // 小顶堆，这个和我们实现的 PriorityQueue 有点区别哟
    // priority_queue<int, vector<int>, greater<int>> cppPQ;

    // 自定义大顶堆
    priority_queue<int, vector<int>, decltype(&compare_int)> cppPQ(compare_int);

    cppPQ.push(13);
    cppPQ.push(10);
    cppPQ.push(56);

    cout << to_string(cppPQ.top()) << endl;
    cppPQ.pop();
    cout << to_string(cppPQ.top()) << endl;
    cppPQ.pop();

    return 0;
}

