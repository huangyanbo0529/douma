/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <iostream>

using namespace std;

class MaxAreaOfIsland1 {
private:
    int rows;
    int cols;
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int maxAreaOfIsland(vector<vector<int>> grid) {
        rows = grid.size();
        if (rows == 0) return 0;

        cols = grid[0].size();
        this->grid = grid;

        int res = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1) {
                    res = max(dfs(row, col), res);
                }
            }
        }
        return res;
    }

    int dfs(int row, int col) {
        grid[row][col] = 0;
        int res = 1;
        for (vector<int> dir : directions) {
            int nextRow = row + dir[0];
            int nextCol = col + dir[1];
            if (inArea(nextRow, nextCol)
                && grid[nextRow][nextCol] == 1) {
                res += dfs(nextRow, nextCol);
            }
        }
        return res;
    }

    bool inArea(int row, int col) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

};

int main() {
    vector<vector<int>> grid = {
            {0,0,1,0,0,0,0,1,0,0,0,0,0},
            {0,0,1,0,0,0,0,1,1,1,0,0,0},
            {0,1,0,0,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,1,1,0,0,1,0,1,0,0},
            {0,1,0,0,1,1,0,0,1,1,1,0,0},
            {0,0,1,0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,0,0,0,0,0,0,1,1,0,0,0,0},
    };
    MaxAreaOfIsland1 maxAreaOfIsland;

    cout << to_string(maxAreaOfIsland.maxAreaOfIsland(grid));

    return 0;
}