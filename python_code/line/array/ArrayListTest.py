# 抖码算法，让算法学习变得简单有趣
# 作者：老汤
from line.array.ArrayList import ArrayList

if __name__ == '__main__':
    arrayList = ArrayList()
    print(arrayList.isEmpty())

    arrayList.addFirst(34)
    arrayList.addLast(23)
    arrayList.add(2, 50)
    print(arrayList.isEmpty())

    print(arrayList.toString())

    arrayList.remove(1)
    print(arrayList.toString())

    arrayList.removeElement(1)
    print(arrayList.toString())

    arrayList1 = ArrayList()
    arrayList1.add(0, "hello")
    arrayList1.addLast("world")
    print(arrayList1.toString())