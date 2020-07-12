// https://practice.geeksforgeeks.org/problems/longest-common-substring/0
#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int n, int m)
{
	vector< vector<int> > L(n, vector<int>(m));
	int max_length = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			// corner case
			if (i == 0 || j == 0)
			{
				if (a[i] == b[j])
					L[i][j] = 1;
				else
					L[i][j] = 0;
			}
			else
			{
				if (a[i] == b[j])
					L[i][j] = L[i - 1][j - 1] + 1;
				else
					L[i][j] = 0;
			}
			if (L[i][j] > max_length)
				max_length = L[i][j];
		}
	}
	// print_2d(L);
	return max_length;
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
		int n, m;
		cin >> n >> m;
		string a, b;
		cin >> a >> b;
		cout << lcs(a, b, n, m) << endl;
	}
	return 0;
}