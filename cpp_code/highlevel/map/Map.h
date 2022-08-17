/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/#ifndef CPP_CODE_MAP_H
#define CPP_CODE_MAP_H

template <typename K, typename V>
class Map {
    /**
     * 获取映射中存储的键值对的数量大小
     * @return
     */
    virtual int size() = 0;

    /**
     * 判断 Map 是否为空
     * @return
     */
    virtual bool isEmpty() = 0;

    /**
     * 向 Map 中添加一对键值对
     * @param key
     * @param value
     */
    virtual void add(K key, V&& value) = 0;

    /**
     * 删除指定键的键值对，并返回删除的键值对的值
     * @param key
     * @return
     */
    virtual V* remove(K key) = 0;

    /**
     * 更新指定的键的值为新指定的值
     * @param key
     * @param newValue
     */
    virtual void set(K key, V&& newValue) = 0;

    /**
     * 根据指定的键查询对应的值
     * @param key
     * @return
     */
    virtual V* get(K key) = 0;

    /**
     * 判断 Map 中是否包含指定的键
     * @param key
     * @return
     */
    virtual bool containsKey(K key) = 0;
};

static int intHash(const int &a) {
    return a;
}

static bool intEqual(const int &a, const int &b) {
    return a == b;
}

#endif //CPP_CODE_MAP_H
