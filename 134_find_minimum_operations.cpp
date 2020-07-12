// https://practice.geeksforgeeks.org/problems/find-optimum-operation/0
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
		// binary representation digits
		int digit_cnt = 0, set_bits = 0;

		while (n)
		{
			if (n & 1)
			{
				set_bits++;
			}

			digit_cnt++;
			n = n / 2;
		}
		// logic = divisions required = digit_cnt - 1;
		//					+
		// 			subtractions required = set_bits
		cout << digit_cnt - 1 + set_bits << endl;

	}
	return 0;
}