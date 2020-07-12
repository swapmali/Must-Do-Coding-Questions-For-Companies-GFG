// https://practice.geeksforgeeks.org/problems/rotate-bits/0
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
		int n, d;
		cin >> n >> d;
		int m1 = pow(2, 15), m2 = 1;
		d = d % 16;
		// left rotation
		int times = d, num = n;
		while (times--)
		{
			// if 16 bit is set add it on right side
			if (num & m1)
			{
				// left shift
				num *= 2;
				num = num | 1;
			}
			else
			{
				num *= 2;
			}
		}
		cout << num << endl;

		// right rotation
		times = d, num = n;
		while (times--)
		{
			// if 16 bit is set add it from left side
			if (num & 1)
			{
				// right shift
				num /= 2;
				num = num | m1;
			}
			else
			{
				num /= 2;
			}
		}
		cout << num << endl;

	}
	return 0;
}