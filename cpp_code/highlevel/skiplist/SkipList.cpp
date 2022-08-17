/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <math.h>

using namespace std;

// 表示跳表的高度，包括原始链表这一层
static int MAX_LEVEL = 16;


/**
 * 跳表的节点，每个节点记录了当前节点数据和所在层的下一个节点
 */
template <typename E>
struct Node {
    E data;
    /*
    表示当前节点在所有层的下一个节点的指针，从上层切换到下层，就是数组下标减去 1
        nextNodes[0] 表示当前节点在第一层的下一个节点
        nextNodes[1] 表示当前节点在第二层的下一个节点
        nextNodes[2] 表示当前节点在第三层的下一个节点
        nextNodes[3] 表示当前节点在第四层的下一个节点
        ...
        nextNodes[15] 表示当前节点在第十六层的下一个节点
    */
    vector<Node<E>*> nextNodes;

    // 记录这个节点维护的索引节点的最大高度
    int maxIndexLevel = 0;

    Node(E data) {
        this->data = data;
        nextNodes.resize(MAX_LEVEL);
    }
};

template <typename E, typename Compare>
class SkipList {
private:
    // 表示当前跳表最大的高度 (包含了原始链表层，所以默认初始值是 1)
    int levelCount;
    // 虚拟头头节点
    Node<E>* dummyHead;
    Compare __comp;

    Node<E>* get(E e) {
        Node<E>* curr = dummyHead;
        // 从最高一层往下一层一层的寻找查找元素所在的区间
        for (int i = levelCount - 1; i >= 0; i--) {
            while (curr->nextNodes[i] != nullptr
                   && __comp(e, curr->nextNodes[i]->data) >= 0) {
                curr = curr->nextNodes[i];
            }
        }

        if (curr->nextNodes[0] != nullptr
            && __comp(e, curr->nextNodes[0]->data) == 0) {
            return curr->nextNodes[0];
        }

        return nullptr;
    }

    /**
     * 随机 level 次，如果是奇数层数 +1，防止伪随机
     *
     * @return
     */
    int randomLevel() {
        int level = 1;
        for (int i = 1; i < MAX_LEVEL; i++) {
            if (rand() % 2 == 1) {
                level++;
            }
        }
        return level;
    }

public:
    SkipList(Compare __comp): levelCount(1), dummyHead(new Node<E>(-1)), __comp(__comp) {}

    bool contains(E e) {
        return get(e) != nullptr;
    }

    void add(E e) {
        // 维护一层索引
        int level = dummyHead->nextNodes[0] == nullptr ? 1 : randomLevel();
        // 先将两层的前一个节点都初始化为虚拟头节点
        vector<Node<E>*> prevNodes(level);
        for (int i = 0; i < level; i++) {
            prevNodes[i] = dummyHead;
        }

        // 1. 找到节点要插入的位置的前一个节点 prev
        Node<E>* prev = dummyHead;
        for (int i = levelCount - 1; i >= 0; i--) {
            while (prev->nextNodes[i] != nullptr
                   && __comp(prev->nextNodes[i].data, e) < 0) {
                prev = prev->nextNodes[i];
            }

            // 维护每一层的前一个节点
            if (i < level)
                prevNodes[i] = prev;
        }

        // 2. 在每一层的正确的位置插入新节点
        Node<E>* newNode = new Node<E>(e);
        newNode->maxIndexLevel = level;
        for (int i = 0; i < level; i++) {
            newNode->nextNodes[i] = prevNodes[i]->nextNodes[i];
            prevNodes[i]->nextNodes[i] = newNode;
        }

        // 更新链表的高度
        if (levelCount < level) levelCount = level;
    }

    void remove(E e) {
        // 1. 找到需要删除节点的前一个节点，以及删除节点对应的索引节点的前一个索引节点
        vector<Node<E>*> prevNodes(levelCount);
        Node<E>* prev = dummyHead;
        for (int i = levelCount - 1; i >= 0; i--) {
            while (prev->nextNodes[i] != nullptr
                   && __comp(prev->nextNodes[i].data, e) < 0) {
                prev = prev->nextNodes[i];
            }

            prevNodes[i] = prev;
        }

        // 2. 对每一层进行删除节点
        // 先判断节点是否存在，存在的话才执行删除
        if (prev->nextNodes[0] != nullptr
            && __comp(prev->nextNodes[0].data, e) == 0) {
            // 对每一层进行删除节点
            for (int i = levelCount - 1; i > 0; i--) {
                Node<E>* delNode = prevNodes[i]->nextNodes[i];
                if (delNode != nullptr && __comp(delNode->data, e) == 0) {
                    prevNodes[i]->nextNodes[i] = delNode->nextNodes[i];
                    delNode->nextNodes[i] = nullptr;
                }
            }
        }
    }
};

