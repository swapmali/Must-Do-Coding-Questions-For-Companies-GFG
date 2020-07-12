// https://practice.geeksforgeeks.org/problems/coin-piles/0
// This is the answer for advance version of the problem mentioned in above link
// Advancement: When we can not only remove coins from the piles but can also add the removed coins to other piles.
#include <bits/stdc++.h>
using namespace std;

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
		vector<int> a(n);

		for (int i = 0; i < n; ++i)
			cin >> a[i];

		sort(a.begin(), a.end(), greater<int>());
		for (int i = 0; i < n; ++i)
		{
			cout << a[i] << " ";
		}
		cout << "\n\n";

		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			int j = i + 1;
			while (j < n)
			{
				int next_diff = abs(a[i] - a[i + 1]);
				while (a[i] > a[j] && abs(a[i] - a[j]) > k && next_diff <= k)
				{
					a[i]--;
					a[j]++;
					cnt++;
				}
				j++;
			}
			// cout << cnt << endl;
		}
		cout << "CNT: " << cnt << endl;
		cout << "checking----" << endl;
		for (int i = 0; i < n; ++i)
		{
			cout << a[i] << " ";
		}
		cout << "\n\n";

		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				cout << abs(a[i] - a[j]) << " ";
				if (abs(a[i] - a[j] > k))
				{
					cout << "ERR: " << a[i] << " " << a[j] << endl;
				}
			}
		}
		cout << "---------------------------------------------------" << endl;
	}
	return 0;
}