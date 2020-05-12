// https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0/
#include <bits/stdc++.h>
using namespace std;

void print_vector(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int get_ind(string s, int l, int r, char c)
{
	for (int i = l; i <= r; ++i)
	{
		if (s[i] == c)
			return i;
	}
	return -1;
}


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
		// cout << s << endl;
		vector<int> hash(256, 0);

		int l = 0, r = 0, max_size_so_far = 0;
		while (l <= r && r < s.length())
		{
			// cout << "l:" << l << " r:" << r << endl;
			if (!hash[s[r]])
			{

				hash[s[r]] = 1;
				int cur_size = r - l + 1;
				if (max_size_so_far < cur_size)
				{
					max_size_so_far = cur_size;
				}
				r++;
			}
			else
			{
				int ind = get_ind(s, l, r - 1, s[r]);
				for (int i = l; i <= ind; ++i)
				{
					hash[s[i]] = 0;
				}

				if (ind != -1)
				{
					l = ind + 1;
				}
			}
		}
		cout << max_size_so_far << endl;
	}
	return 0;
}