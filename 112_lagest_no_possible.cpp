// https://practice.geeksforgeeks.org/problems/largest-number-possible/0

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
		int n, s;
		cin >> n >> s;
		if (!s)
		{
			cout << -1 << endl;
			continue;
		}

		vector<int> a(n, 0);

		for (int i = 0; i < n; ++i)
		{
			int tmp = s - 9;
			if (tmp >= 0)
			{
				a[i] = 9;
			}
			else if (s >= 0)
			{
				a[i] = s;
			}
			else
			{
				break;
			}
			s -= 9;
		}

		if (s > 0)
			cout << -1 << endl;
		else
		{
			for (int i = 0; i < n; ++i)
				cout << a[i];
			cout << endl;
		}
	}
	return 0;
}