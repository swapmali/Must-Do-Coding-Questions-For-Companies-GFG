// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/
#include <bits/stdc++.h>
using namespace std;

void print_2d(vector<vector<int> > v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
		{
			cout << v[i][j] << " ";
		}
	}
	cout << endl;
}

void flood_fill(vector< vector<int> > &M, int x, int y, int k)
{
	if (M[x][y] == k)
		return;

	int n = M.size();
	int m = M[0].size();

	int cur_color = M[x][y];
	M[x][y] = k;

	if (x + 1 < n && M[x + 1][y] == cur_color)
		flood_fill(M, x + 1, y, k);

	if (y + 1 < m && M[x][y + 1] == cur_color)
		flood_fill(M, x, y + 1, k);

	if (x - 1 >= 0 && M[x - 1][y] == cur_color)
		flood_fill(M, x - 1, y, k);

	if (y - 1 >= 0 && M[x][y - 1] == cur_color)
		flood_fill(M, x, y - 1, k);
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m, x, y, k;
		cin >> n >> m;
		vector< vector<int> > M(n, vector<int>(m));

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cin >> M[i][j];
		}
		cin >> x >> y >> k;
		flood_fill(M, x, y, k);
		print_2d(M);
	}
	return 0;
}