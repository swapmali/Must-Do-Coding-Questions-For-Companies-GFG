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
		string s, temp;
		cin >> s;
		int is_repeated = 1;
		temp = s;
		while (is_repeated)
		{
			s = temp;
			temp = "";
			is_repeated = 0;
			for (int i = 0; i < s.length(); ++i)
			{
				char cur_char = s[i];
				int cur_ind = i;
				//cout << cur_char << " ";
				while (s[i + 1] == cur_char)
				{
					is_repeated = 1;
					i++;
				}
				if (cur_ind == i)
				{
					// cout << cur_char << endl;
					temp += cur_char;
				}
			}

		}
		cout << temp << endl;
	}
	return 0;
}