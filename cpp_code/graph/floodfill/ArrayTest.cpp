/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <iostream>

using namespace std;

static vector<int> twoDimConvertOneDim(vector<vector<int>> arr) {
    int rows = arr.size();
    int cols = arr[0].size();

    vector<int> res(rows * cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            res[index] = arr[i][j];
        }
    }

    return res;
}

static vector<vector<int>> oneDimConvertTwoDim(vector<int> arr, int rows, int cols) {
    vector<vector<int>> res(rows, vector<int>(cols));
    for (int index = 0; index < arr.size(); index++) {
        int i = index / cols;
        int j = index % cols;
        res[i][j] = arr[index];
    }
    return res;
}

static void printAdj(vector<vector<int>> arr, int i, int j) {
    int rows = arr.size();
    int cols = arr[0].size();

    vector<vector<int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    for (vector<int> dir : directions) {
        int row = i + dir[0];
        int col = j + dir[1];
        if (row < rows && col < cols && row >= 0 && col >= 0) {
            cout << to_string(arr[row][col]) << endl;
        }
    }
}