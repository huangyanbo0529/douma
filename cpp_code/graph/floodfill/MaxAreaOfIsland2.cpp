/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class MaxAreaOfIsland2 {
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
                    int currOnes = 0;
                    stack<vector<int>> s;
                    s.push({row, col});
                    // bug 修复，每次将元素 push 到栈中都要将其设置为 0
                    grid[row][col] = 0;
                    while (!s.empty()) {
                        vector<int> curr = s.top();
                        s.pop();
                        int currRow = curr[0], currCol = curr[1];
                        currOnes++;
                        for (vector<int> dir : directions) {
                            int nextRow = currRow + dir[0];
                            int nextCol = currCol + dir[1];
                            if (inArea(nextRow, nextCol)
                                && grid[nextRow][nextCol] == 1) {
                                s.push({nextRow, nextCol});
                                // bug 修复，每次将元素 push 到栈中都要将其设置为 0
                                grid[nextRow][nextCol] = 0;
                            }
                        }
                    }
                    res = max(res, currOnes);
                }
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
    MaxAreaOfIsland2 maxAreaOfIsland;

    cout << to_string(maxAreaOfIsland.maxAreaOfIsland(grid));

    return 0;
}