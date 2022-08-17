class Person:

    def __init__(self, name, age):
        self.name = name
        self.age = age


def compare(p):
    return p.age


data = [Person("douma", 40), Person("laotang", 30), Person("douma1", 32), Person("laotang2", 33)]
# sort 默认是升序排列 reverse = True 表示降序排列
# key接受的是一个只有一个形参的函数
data.sort(key=compare, reverse=True)
for p in data:
    print(p.name + ":" + str(p.age))
