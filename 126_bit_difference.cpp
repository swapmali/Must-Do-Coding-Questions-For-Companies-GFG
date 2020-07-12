// https://practice.geeksforgeeks.org/problems/bit-difference/0
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
		int a, b;
		cin >> a >> b;
		int m = 1;
		int cnt = 0;

		while (a >= m || b >= m)
		{
			if ( ((a & m) && !(b & m)) || ( !(a & m) && (b & m)))
				cnt++;
			m *= 2;
		}
		cout << cnt << endl;
	}
	return 0;
}