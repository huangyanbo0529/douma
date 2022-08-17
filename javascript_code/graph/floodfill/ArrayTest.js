
// 二维数组转一维数组
function twoDimConvertOneDim(arr) {
    const rows = arr.length
    const cols = arr[0].length

    const res = new Array(rows * cols).fill(0)
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            const index = i * cols + j
            res[index] = arr[i][j]
        }
    }
    return res
}

// 一维数组转二维数组
function oneDimConvertTwoDim(arr, rows, cols) {
    const res = new Array(rows).fill(0).map(() => new Array(cols).fill(0))
    for (let index = 0; index < arr.length; index++) {
        const i = Math.floor(index / cols)
        const j = Math.floor(index % cols)
        res[i][j] = arr[index]
    }
    return res
}

// 打印一个数组中指定元素的周围八个方向上相邻的元素
function printAdj(arr, i, j) {
    const rows = arr.length
    const cols = arr[0].length

    const directions = [
        [-1, 0], [1, 0], [0, -1], [0, 1],
        [-1, -1], [-1, 1], [1, -1], [1, 1]
    ]

    for (const dir of directions) {
        const row = i + dir[0]
        const col = j + dir[1]
        if (row < rows && col < cols && row >= 0 && col >= 0) {
            console.log(arr[row][col])
        }
    }
}

data = [
    [4, 2, 5, 11],
    [3, 7, 1, 9],
    [32, 22, 13, 8]
]
console.log(twoDimConvertOneDim(data))

arr = [4, 2, 5, 11, 3, 7, 1, 9, 32, 22, 13, 8]
res = oneDimConvertTwoDim(arr, 3, 4)
for (const a of res) {
    console.log(a)
}

printAdj(data, 0, 0)