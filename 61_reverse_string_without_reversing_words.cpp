// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

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
		string s;
		cin >> s;
		reverse(s.begin() , s.end());
		// cout << s << endl;
		int start = 0, end = -1;
		for (int i = 0; i < s.length(); ++i)
		{
			start = end + 1;
			while (s[i] != '.' && i < s.length())
			{
				i++;
			}
			end = i;
			// cout << start << " " << end << endl;
			reverse(s.begin() + start, s.begin() + end);
		}
		cout << s << endl;
	}
	return 0;
}