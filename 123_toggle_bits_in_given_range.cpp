// https://practice.geeksforgeeks.org/problems/toggle-bits-given-range/0/
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
		int n, l, r;
		cin >> n >> l >> r;
		int digit = 1, m = 1;
		while (n >= m)
		{
			if (digit >= l && digit <= r)
				n = n ^ m;
			m *= 2;
			digit++;
		}
		cout << n << endl;
	}
	return 0;
}