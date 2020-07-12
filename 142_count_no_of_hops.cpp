// https://practice.geeksforgeeks.org/problems/count-number-of-hops/0
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
		vector<int> f(n + 1);

		f[0] = 1;
		f[1] = 1;
		f[2] = 2;

		for (int i = 3; i < n + 1; ++i)
			f[i] = f[i - 1] + f[i - 2] + f[i - 3];

		cout << f[n] << endl;
	}
	return 0;
}