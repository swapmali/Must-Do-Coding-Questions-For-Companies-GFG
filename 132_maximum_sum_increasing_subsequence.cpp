// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/
#include <bits/stdc++.h>
using namespace std;

int msis(vector<int> v, int n)
{
	vector<int> L(n);

	// initialize by each ele own value
	for (int i = 0; i < n; ++i)
	{
		L[i] = v[i];
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (v[j] < v[i])
			{
				L[i] = max(L[i], L[j] + v[i]);
			}
		}
	}

	int max_sum = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		if (max_sum < L[i])
			max_sum = L[i];
	}
	return max_sum;
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
		int n;
		cin >> n;
		vector<int> v(n);

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		cout << msis(v, n) << endl;

	}
	return 0;
}