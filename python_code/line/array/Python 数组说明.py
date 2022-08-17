"""
Python3 中没有显示的静态数组，通过下面创建的数组是动态数组：
    arr = []
或者：
    arr = list()

以上都是创建的动态数组，和 Java 中的 ArrayList 等价
Python3 的数组中支持的 API 也和 Java 中的 ArrayList 差不多
"""

arr = []
# 如果指定数组长度为 10 的话可以这样：
arr = [0] * 10

arr = list()
"""
新增操作 
"""
# 向数组中的最后添加一个元素，相当于 addLast
# 时间复杂度 O(1)
arr.append(80)

# 在数组的开头添加一个元素，相当于 addFirst
# 时间复杂度 O(n)
arr.insert(0, 23)
arr.insert(0, 2)

# 向指定索引位置添加一个新元素，会自动扩容
# 时间复杂度 O(n)
arr.insert(1, 222)

"""
查询操作
"""
# 获取 index 索引位置的元素
# 时间复杂度 O(1)
e = arr[3]

print(arr)