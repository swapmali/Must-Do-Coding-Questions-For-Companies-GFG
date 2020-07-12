// https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not/0
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
		int m = 1 * pow(2, k);
		int digit = 0;

		if (n & m)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}