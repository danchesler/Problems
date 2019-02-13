/*
There are N students in a class. Some of them are friends, while some are not. 
Their friendship is transitive in nature. 
For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. 
And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. 
If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. 
And you have to output the total number of friend circles among all the students.
*/

int findCircleNum(vector<vector<int>>& M) {
	vector<int> groups(M.size(), false); // want to check rows 0 to M.size()-1
	stack<int> dfs;
	int circles = 0;
	int cur = 0;

	for (int i = 0; i < groups.size(); i++) // want to check members 0-3 if any are in friend groups
	{
		for (int j = 0; j < M[i].size(); j++) // check row for a 1
		{
			if (!groups[j] && (M[j][i] == 1))
			{
				circles++;
				dfs.push(i);
				break;
			}
		}
		
		while (!dfs.empty())
		{
			cur = dfs.top();
			dfs.pop();
			groups[cur] = true;

			for (int k = 0; k < M[cur].size(); k++)
			{
				if (!groups[k] && (M[cur][k] == 1))
					dfs.push(k);
			}
		}

	}

	return circles;
}