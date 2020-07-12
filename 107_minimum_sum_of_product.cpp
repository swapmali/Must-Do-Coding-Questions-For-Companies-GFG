// https://practice.geeksforgeeks.org/problems/minimize-the-sum-of-product/0
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
		int n;
		cin >> n;
		vector<long long int> a(n), b(n);

		for (int i = 0; i < n; ++i)
			cin >> a[i];

		for (int i = 0; i < n; ++i)
			cin >> b[i];


		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<int>());

		long long int output = 0;
		for (int i = 0; i < n; ++i)
		{
			output += a[i] * b[i];
		}
		cout << output << endl;
	}
	return 0;
}