// https://practice.geeksforgeeks.org/problems/coin-change/0
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
		cout << endl;
	}
}

// coin change matrix
int ccm(vector<int>c, int n, int N)
{
	vector<vector<int> > T(n + 1, vector<int>(N + 1));

	// initialize 0th row by 0's
	for (int j = 0; j < N + 1; ++j)
	{
		T[0][j] = 0;
	}

	// initialize 0th col by 1's
	for (int i = 0; i < n + 1; ++i)
	{
		T[i][0] = 1;
	}

	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < N + 1; ++j)
		{
			if (j >= c[i - 1])
				T[i][j] = T[i - 1][j] + T[i][j - c[i - 1]];
			else
				T[i][j] = T[i - 1][j];
		}
	}
	// print_2d(T);
	return T[n][N];
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
		int n, N;
		cin >> n;
		vector<int> c(n);

		for (int i = 0; i < n; ++i)
			cin >> c[i];

		cin >> N;

		cout << ccm(c, n, N) << endl;

	}
	return 0;
}