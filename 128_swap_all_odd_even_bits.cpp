// https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits/0
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
		int n, digit = 1;
		cin >> n;
		int m1 = 1, m2 = 2;
		while (1)
		{
			int bit1 = 0, bit2 = 0;
			if (n & m1)
			{
				bit1 = 1;
			}
			if (n & m2)
			{
				bit2 = 1;
			}
			int r1, r2;

			r1 = m1;
			if (bit2)
			{
				n = n | r1;
			}
			else
			{
				r1 = ~r1;
				n = n & r1;
			}

			r2 = m2;
			if (bit1)
			{
				n = n | r2;
			}
			else
			{
				r2 = ~r2;
				n = n & r2;
			}

			if (n < m2 && !bit1 & !bit2)
				break;
			// left shift 2 times
			m1 *= 4;
			m2 *= 4;

		}
		cout << n << endl;
	}
	return 0;
}