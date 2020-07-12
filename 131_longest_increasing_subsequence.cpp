// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> v, int n)
{
	vector<int> L(n, 1);

	for (int i = 1; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (v[j] < v[i])
			{
				L[i] = max(L[i], L[j] + 1);
			}
		}
	}

	int max_length = 1;
	for (int i = 0; i < n; ++i)
	{
		if (max_length < L[i])
			max_length = L[i];
	}
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
		int n;
		cin >> n;
		vector<int> v(n);

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		cout << lis(v, n) << endl;

	}
	return 0;
}