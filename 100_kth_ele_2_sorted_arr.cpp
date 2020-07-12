// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/

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
		int m, n, pos;
		cin >> m >> n >> pos;
		vector<int> a(m), b(n);

		for (int i = 0; i < m; ++i)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> b[i];
		}
		pos--;
		int i = 0, j = 0, k = 0, selected, flg = 0;
		while (i <= pos && j < a.size() && k < b.size())
		{
			// cout << "i:" << i << endl;
			if (a[j] < b[k])
			{
				selected = a[j];
				j++;
			}
			else
			{
				selected = b[k];
				k++;
			}

			// cout << "selected:" << selected << endl;
			if (i == pos)
			{
				cout << selected << endl;
				flg = 1;
				break;
			}

			i++;
		}

		// means kth position doesn't arrived just yet
		if (!flg)
		{
			while (j < a.size())
			{
				if (i == pos)
				{
					cout << a[j] << endl;
					break;
				}
				j++;
				i++;
			}

			while (k < b.size())
			{
				if (i == pos)
				{
					cout << b[k] << endl;
					break;
				}
				k++;
				i++;
			}
		}


	}
	return 0;
}