// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem/0

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
		long int n, k, sum = 0;
		cin >> n;
		vector<int> arr(n);

		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		cin >> k;
		if (sum % k == 0 && n % 2 == 0)
			cout << "True" << endl;
		else
			cout << "False" << endl;

	}
	return 0;
}