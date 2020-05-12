// https://practice.geeksforgeeks.org/problems/implement-atoi/1

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

void print_2d_vector(vector< vector<int> > v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
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
		int n = 0, l = 0, flg = 0;
		if (s[0] == '-')
			l = 1;
		for (int i = l; i < s.length(); ++i)
		{
			// cout << int(s[i]) << " " ;
			if (s[i] >= 48 && s[i] <= 57)
			{
				n = n * 10 + (s[i] - 48);
			}
			else
			{
				flg = 1;
				break;
			}
		}
		cout << endl;
		if (flg)
			cout << -1 << endl;
		else
		{
			if (l)
				cout << n * -1 << endl;
			else
				cout << n << endl;
		}
	}
	return 0;
}