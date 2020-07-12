// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> w, vector<int> p, int n, int W)
{
	vector< vector<int> > KS(n, vector<int>(W + 1));

	// initialize first column to 0's
	for (int i = 0; i < n; ++i)
		KS[i][0] = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < W + 1; ++j)
		{
			// corner case
			if (i - 1 < 0)
			{
				// current ks capacity is able to include current item weight
				if (w[i] <= j)
				{
					KS[i][j] = p[i];
				}
				else
				{
					KS[i][j] = 0;
				}
			}

			else
			{
				if (w[i] <= j)
				{
					KS[i][j] = max((p[i] + KS[i - 1][j - w[i]]), KS[i - 1][j]);
				}
				else
				{
					KS[i][j] = KS[i - 1][j];
				}
			}
		}
	}
	return KS[n - 1][W];
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
		int n, W;
		cin >> n >> W;
		vector<int> w(n), p(n);

		for (int i = 0; i < n; ++i)
			cin >> p[i];
		for (int i = 0; i < n; ++i)
			cin >> w[i];

		cout << knapsack(w, p, n, W) << endl;


	}
	return 0;
}