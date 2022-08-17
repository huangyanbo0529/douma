from typing import List


# 将二维数组转成一维数组
def twoDimConvertOneDim(arr) -> List[int]:
    rows, cols = len(arr), len(arr[0])
    res = [0] * (rows * cols)
    for i in range(rows):
        for j in range(cols):
            index = i * cols + j
            res[index] = arr[i][j]
    return res

# 将一维数组转成二维数组
def oneDimConvertTwoDim(arr, rows, cols) -> List[List[int]]:
    res = [[0] * cols for _ in range(rows)]
    for index in range(len(arr)):
        i = index // cols
        j = index % cols
        res[i][j] = arr[index]
    return res

# 找出一个元素的四周八个方向上的元素
def printAdj(arr, i, j) -> None:
    rows, cols = len(arr), len(arr[0])
    directions = [
        [-1, 0], [1, 0], [0, -1], [0, 1],
        [-1, -1], [-1, 1], [1, -1], [1, 1]
    ]
    for dir in directions:
        row = i + dir[0]
        col = j + dir[1]
        if 0 <= row < rows and 0 <= col < cols:
            print(arr[row][col])


if __name__ == '__main__':
    data = [
        [4, 2, 5, 11],
        [3, 7, 1, 9],
        [32, 22, 13, 8]
    ]
    print(twoDimConvertOneDim(data))

    arr = [4, 2, 5, 11, 3, 7, 1, 9, 32, 22, 13, 8]
    print(oneDimConvertTwoDim(arr, 3, 4))

    printAdj(data, 0, 0)
