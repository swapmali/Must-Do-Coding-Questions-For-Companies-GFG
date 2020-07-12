// https://practice.geeksforgeeks.org/problems/set-kth-bit/0/
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

		n = n | m;
		cout << n << endl;
	}
	return 0;
}