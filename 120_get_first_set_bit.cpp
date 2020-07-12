// https://practice.geeksforgeeks.org/problems/find-first-set-bit/0
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
		int m = 1, i = 1;
		int digit = 0;

		while (n >= m)
		{
			if (n & m)
			{
				digit = i;
				break;
			}

			// left shift by 1 digit
			m *= 2;

			i++;
		}
		cout << digit << endl;
	}
	return 0;
}