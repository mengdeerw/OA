//https://leetcode.com/discuss/interview-question/411357/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int minHours(int rows, int columns, vector<vector<int>>& grid) {
	if (grid.empty() || grid[0].empty()) return 0;
	queue<pair<int, int>> q;
	int humanCount = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (grid[i][j] == 1) q.push({i, j});
			else humanCount++;
		}
	}

	int hours = 0;
	int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (!q.empty() && humanCount > 0) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			auto curr = q.front();
			q.pop();
			for (auto dir: dirs) {
				int newRow = curr.first + dir[0];
				int newCol = curr.second + dir[1];

				if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns && grid[newRow][newCol] == 0) {
					q.push({newRow, newCol});
					grid[newRow][newCol] = 1;
					humanCount--;
				}
			}
		}
		hours++;
	}

	return humanCount == 0?hours:-1;
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
    };
    int row = grid.size(), col = grid[0].size();
    cout << minHours(row, col, grid) << endl;
    
    return 0;
}
