// https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0

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
		string a, b;
		cin >> a >> b;
		string s = a;
		int n = s.length();
		rotate(s.begin(), s.begin() + 2 , s.end());
		int flg = 0;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] != b[i])
			{
				flg = 1;
				break;
			}
		}
		if (!flg)
			cout << 1 << endl;
		else
		{
			s = a;
			rotate(s.begin(), s.begin() + n - 2, s.end());
			// cout << s << endl;
			int flg = 0;
			for (int i = 0; i < n; ++i)
			{
				if (s[i] != b[i])
				{
					flg = 1;
					break;
				}
			}
			if (!flg)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}

	}
	return 0;
}