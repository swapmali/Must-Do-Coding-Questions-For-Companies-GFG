// https://practice.geeksforgeeks.org/problems/shop-in-candy-store/0

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

		sort(a.begin(), a.end());

		int min_money = 0, max_money = 0;

		int i = 0, j = n;
		while (i < j)
		{
			min_money += a[i];
			i++;
			j -= k;
		}
		cout << min_money << " ";

		i = -1, j = n - 1;
		while (i < j)
		{
			max_money += a[j];
			i += k;
			j--;
		}
		cout << max_money << endl;

	}
	return 0;
}