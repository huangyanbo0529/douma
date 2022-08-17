# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
from collections import deque


class FIFOCache:
    def __init__(self, capacity):
        self.cache = dict()
        self.queue = deque()
        self.capacity = capacity

    def get(self, key):
        if key in self.cache:
            return self.cache[key]
        return None

    def put(self, key, value):
        if key not in self.cache:
            if len(self.cache) == self.capacity:
                old_key = self.queue.popleft()
                del self.cache[old_key]
            self.queue.append(key)
        self.cache[key] = value


if __name__ == '__main__':
    cache = FIFOCache(3)
    cache.put(1, 1)
    cache.put(2, 2)
    cache.put(3, 3)
    cache.put(4, 4)
    print(cache.get(3))
    cache.put(4, 5)
    print(cache.get(4))
    cache.put(5, 6)
    print(cache.get(2))