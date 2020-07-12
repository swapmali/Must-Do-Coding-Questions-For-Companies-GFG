// https://practice.geeksforgeeks.org/problems/power-of-2/0
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
		long long int n;
		cin >> n;
		long long int m = 1;
		int set_cnt = 0;

		while (n >= m)
		{
			if (n & m)
			{
				set_cnt++;
				if (set_cnt > 1)
					break;
			}

			m *= 2;
		}
		if (set_cnt == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}