// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
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

int egg_drop(int n, int k)
{
	// T[i][j] stores min attempts required for i eggs and n floors
	vector< vector<int> > T(n + 1, vector<int> (k + 1));

	// initialize first row to 0's
	for (int i = 0; i < k + 1; ++i)
		T[0][i] = 0;
	// initialize first col to 0's
	for (int i = 0; i < n + 1; ++i)
		T[i][0] = 0;
	// initialize row of eggs 1 to col no.
	for (int i = 0; i < k + 1; ++i)
		T[1][i] = i;
	// initialize col of floor 1 to 1's.
	for (int i = 0; i < n + 1; ++i)
		T[i][1] = 1;


	// main code
	for (int i = 2; i < n + 1; ++i)
	{
		for (int j = 2; j < k + 1; ++j)
		{
			// for each [i][j] we need to minimize worst case
			// attempts out of 2 cases (egg breaks or doeasn't break)
			// at each floor below them
			// x is each floor below jth floor
			int min_so_far = INT_MAX;
			for (int x = 1; x < j; ++x)
			{
				int res = 1 + max(T[i - 1][x - 1], T[i][j - x]);

				if (res < min_so_far)
					min_so_far = res;
			}
			T[i][j] = min_so_far;
		}
	}
	// print_2d(T);
	return T[n][k];
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
		int n, k;
		cin >> n >> k;
		cout << egg_drop(n, k) << endl;
	}
	return 0;
}