#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_vector(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << i << ": " << v[i] << endl;
	}
	cout << "hash end" << endl;
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
		int m, n, sum, max = INT_MIN, min = INT_MAX;
		cin >> m >> n >> sum;
		vector<int> a(m), b(n);

		for (int i = 0; i < m; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> b[i];
			if (b[i] > max)
				max = b[i];
			if (b[i] < min)
				min = b[i];
		}
		// cout << max << " " << min << endl;
		int streak = 0;
		if (min < 0)
		{
			streak = abs(min);
		}
		else
		{
			streak = 0;
		}

		vector<int> hash(max + 1 + streak, 0);
		for (int i = 0; i < n; ++i)
		{
			hash[b[i] + streak] = 1;
		}

		// print_vector(hash);
		sort(a.begin(), a.end());
		int flg = 0;
		for (int i = 0; i < m; ++i)
		{

			int diff = (sum - a[i]) + streak;
			// cout << "for " << a[i] << " " << diff << endl;
			if (diff >= 0 && diff < hash.size())
			{
				if (hash[diff] && !flg)
				{
					cout << a[i] << " " << diff - streak;
					flg = 1;
				}
				else if (hash[diff] && flg)
				{
					cout << ", " << a[i] << " " << diff - streak;
				}
			}
		}
		if (!flg)
		{
			cout << -1;
		}
		cout << endl;
	}
	return 0;
}