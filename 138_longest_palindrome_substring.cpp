// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
#include <bits/stdc++.h>
using namespace std;

void print_2d(vector<vector<bool> > v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}


string lps(string a)
{
	int n = a.length();
	std::vector<vector<bool> > L(n, vector<bool>(n));

	int max_length = INT_MIN, start = 0, end = 0;

	// initialize all length 1 substrings true
	for (int i = 0; i < n; ++i)
	{
		L[i][i] = true;
	}

	// for length 2 substrings
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] == a[i + 1])
		{
			L[i][i + 1] = true;
			if (max_length < 2)
			{
				max_length = 2;
				start = i;
				end = i + 1;
			}
		}
		else
			L[i][i + 1] = false;
	}

	// for substrings of length 3 and more
	for (int l = 3; l <= n; ++l)
	{
		for (int i = 0; i <= n - l; ++i)
		{
			int j = i + l - 1;

			if (a[i] == a[j])
			{
				L[i][j] = L[i + 1][j - 1];
				if (L[i][j] && max_length < l)
				{
					max_length = l;
					start = i;
					end = j;
				}
			}
			else
				L[i][j] = false;
		}
	}
	// print_2d(L);
	// cout << max_length << " ind:" << start << " " << end << endl;

	string p;
	for (int i = start; i <= end; ++i)
	{
		p += a[i];
	}
	return p;
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

		cout << lps(s) << endl;

	}
	return 0;
}