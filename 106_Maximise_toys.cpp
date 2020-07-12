// https://practice.geeksforgeeks.org/problems/maximize-toys/0

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
		vector<int> arr(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());

		int i = 0, cnt = 0;
		while (k > 0 && i < n)
		{
			if (arr[i] <= k)
			{
				k -= arr[i];
				cnt++;
			}
			i++;
		}
		cout << cnt << endl;
	}
	return 0;
}