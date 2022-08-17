# 抖码算法，让算法学习变得简单有趣
# 作者：老汤


class LocalCache:
    def __init__(self):
        self.cache = dict()

    def get(self, key):
        return self.cache[key]

    def put(self, key, value):
        self.cache[key] = value