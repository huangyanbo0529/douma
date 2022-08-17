/**
* 抖码算法，让算法学习变的简单有趣
* @作者 : 老汤
*/

#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class MaxAreaOfIsland {
private:
    int rows;
    int cols;
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<bool> visited;

    vector<unordered_set<int>> graph;

public:
    int maxAreaOfIsland(vector<vector<int>> grid) {
        rows = grid.size();
        if (rows == 0) return 0;

        cols = grid[0].size();
        this->grid = grid;

        // 1. 建图
        graph = constructGraph();

        // 2. 求解最大联通分量的顶点数
        this->visited.resize(graph.size());
        fill(this->visited.begin(), this->visited.end(), false);

        int res = 0;
        for (int v = 0; v < graph.size(); v++) {
            int row = v / cols;
            int col = v % cols;
            if (!visited[v] && grid[row][col] == 1) {
                res = max(dfs(v), res);
            }
        }
        return res;
    }

    int dfs(int v) {
        visited[v] = true;
        int res = 1;
        for (int w : graph[v]) {
            if (!visited[w]) {
                res += dfs(w);
            }
        }
        return res;
    }

    vector<unordered_set<int>> constructGraph() {
        vector<unordered_set<int>> g(rows * cols, unordered_set<int>());

        for (int v = 0; v < g.size(); v++) {
            int row = v / cols;
            int col = v % cols;
            if (grid[row][col] == 1) {
                for (vector<int> dir : directions) {
                    int nextRow = row + dir[0];
                    int nextCol = col + dir[1];
                    if (inArea(nextRow, nextCol)
                        && grid[nextRow][nextCol] == 1) {
                        int w = nextRow * cols + nextCol;
                        g[v].insert(w);
                        g[w].insert(v);
                    }
                }
            }
        }
        return g;
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
    MaxAreaOfIsland maxAreaOfIsland;

    cout << to_string(maxAreaOfIsland.maxAreaOfIsland(grid));

    return 0;
}