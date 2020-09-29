//https://leetcode.com/problems/number-of-islands/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int numIslands_bfs(vector<vector<char>>& grid) {
	int result = 0;
	if (grid.empty() || grid[0].empty()) return result;
	
	int row = grid.size(), col = grid[0].size();
	int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	vector<vector<bool>> visited (row, vector<bool>(col, false));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			// only count into result when an island is unvisited before
			if (grid[i][j] == '1' && !visited[i][j]) {
				result++;
				queue<pair<int, int>> q;
				q.push({i, j});
				while (!q.empty()) {
					auto topNode = q.front();
					q.pop();
					for (auto dir: dirs) {
						int newRow = topNode.first + dir[0];
						int newCol = topNode.second + dir[1];
						if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col 
							&& grid[newRow][newCol] == '1' && !visited[newRow][newCol]) {
							visited[newRow][newCol] = true;
							q.push({newRow, newCol});
						}
					}
				}
	
			}
		}
	}
	return result;
}

void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited) {
	if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() 
		|| grid[x][y] == '0' || visited[x][y]) return;
	visited[x][y] = true;
	dfs(grid, x - 1, y, visited);
	dfs(grid, x + 1, y, visited);
	dfs(grid, x, y - 1, visited);
	dfs(grid, x, y + 1, visited);
}

int numIslands_dfs(vector<vector<char>>& grid) {
	int result = 0;
	if (grid.empty() || grid[0].empty()) return result;

	int row = grid.size(), col = grid[0].size();
	vector<vector<bool>> visited (row, vector<bool>(col, false));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] =='1' && !visited[i][j]) {
				result++;
				dfs(grid, i, j, visited);
			}
		}
	}

	return result;     
}

int main() {
	vector<vector<char>> grid = {
	  {'1','1','0','0','0'},
	  {'1','1','0','0','0'},
	  {'0','0','1','0','0'},
	  {'0','0','0','1','1'}
	};
	int num1 = numIslands_bfs(grid);
	int num2 = numIslands_dfs(grid);
	cout << num1 <<endl;
	cout << num2 <<endl;
	return 0;
}
