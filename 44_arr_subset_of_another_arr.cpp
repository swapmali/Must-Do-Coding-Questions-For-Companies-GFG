#include <iostream>
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
		long int m, n, max = 0;
		cin >> m >> n;
		vector<int> a(m), b(n);

		for (long int i = 0; i < m; ++i)
		{
			cin >> a[i];
			if (a[i] > max)
				max = a[i];
		}
		for (long int i = 0; i < n; ++i)
		{
			cin >> b[i];
		}

		std::vector<int> hash(max + 1, 0);
		for (long int i = 0; i < m; ++i)
		{
			hash[a[i]] = 1;
		}

		int flg = 0;
		for (long int i = 0; i < n; ++i)
		{
			if (!hash[b[i]])
			{
				flg = 1;
				break;
			}
		}

		if (!flg)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;


	}
	return 0;
}