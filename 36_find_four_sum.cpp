// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/

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
		long int n, s;
		cin >> n >> s;
		vector<int> v(n);

		for (long int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		std::vector<int> hash(v[v.size() - 1] + 1, 0);

		for (int i = 0; i < n; ++i)
		{
			hash[v[i]]++;
		}
		// cout << "hash: ";
		// print_vector(hash);
		/*
				std::vector<int> :: iterator ip;
				ip = unique(v.begin(), v.end());
				v.resize(distance(v.begin(), ip));*/

		// cout << "v: ";
		// print_vector(v);

		vector < vector<int> > ans;

		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				for (int k = j + 1; k < n; ++k)
				{
					int l = s - (v[i] + v[j] + v[k]);
					if (l >= v[k] && binary_search(v.begin(), v.end(), l))
					{
						vector<int> a(4);
						a[0] = v[i];
						a[1] = v[j];
						a[2] = v[k];
						a[3] = l;
						ans.push_back(a);
					}
				}
			}
		}

		int is_printed = 0, is_repeated = 0;

		for (int i = 0; i < ans.size(); ++i)
		{
			int is_repeated = 0;
			if (i)
			{
				int j = i - 1;
				while (j >= 0)
				{
					if (ans[i][0] == ans[j][0])
					{
						if (ans[i][1] == ans[j][1] && ans[i][2] == ans[j][2] && ans[i][3] == ans[j][3])
						{
							is_repeated = 1;
							//cout << "Repeated for : " << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << " " << endl;
							break;
						}
					}
					else
						break;
					j--;
				}

			}
			if (!is_repeated)
			{
				std::vector<int> h(v[v.size() - 1] + 1, 0);
				for (int j = 0; j < 4; ++j)
				{
					h[ans[i][j]]++;
				}
				// cout << "h: ";
				// print_vector(h);
				int flg = 1;
				for (int j = 0; j < 4; ++j)
				{
					if (h[ans[i][j]] > hash[ans[i][j]])
					{
						flg = 0;
						break;
					}
				}
				if (flg)
				{
					cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << " $";
					is_printed = 1;
				}
			}
		}
		if (!is_printed)
			cout << -1;
		cout << endl;
	}
	return 0;
}