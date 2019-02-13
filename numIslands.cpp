/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/

void dfs(vector<vector<char>>& M, int y, int x)
{
	vector<int> cur;
	stack<vector<int>> stack;

	stack.push({ y, x });

	while (!stack.empty())
	{
		cur = stack.top();
		M[cur[0]][cur[1]] = 'x';
		stack.pop();

		// neighbors: up(y-1, x), down(y+1, x), left(y, x-1), right(y, x+1)
		if (cur[0] - 1 >= 0 && M[cur[0] - 1][cur[1]] == '1')  				// up
			stack.push({ cur[0] - 1, cur[1] });
		if (cur[0] + 1 < M.size() && M[cur[0] + 1][cur[1]] == '1') 			// down
			stack.push({ cur[0] + 1, cur[1] });
		if (cur[1] - 1 >= 0 && M[cur[0]][cur[1] - 1] == '1') 				// left
			stack.push({ cur[0], cur[1] - 1 });
		if (cur[1] + 1 < M[cur[0]].size() && M[cur[0]][cur[1] + 1] == '1') // right
			stack.push({ cur[0], cur[1] + 1 });
	}
}

int numIslands(vector<vector<char>>& grid) {
	int islands = 0;
	// y axis starting from 0 to M.size()-1
	for (int y = 0; y < grid.size(); y++)
	{
		// x axis starting from 0 to M[y].size()-1
		for (int x = 0; x < grid[y].size(); x++)
		{
			if ((grid[y][x] == '1'))
			{
				islands++;
				dfs(grid, y, x);
			}
		}
	}

	return islands;
}