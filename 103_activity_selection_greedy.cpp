// https://practice.geeksforgeeks.org/problems/activity-selection/0

#include <bits/stdc++.h>
using namespace std;

bool mycomp(vector<int> &a, vector<int> &b)
{
	return a[1] < b[1];
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
		int n;
		cin >> n;
		vector< vector<int> > a(n);

		for (int i = 0; i < n; ++i)
		{
			a[i].resize(2);
			cin >> a[i][0];
		}

		for (int i = 0; i < n; ++i)
			cin >> a[i][1];

		sort(a.begin(), a.end(), mycomp);

		/*for (int i = 0; i < n; ++i)
		{
			cout << a[i][0] << " " << a[i][1] << endl;
		}*/

		int cnt = 0, flg = 0;
		int last_finish, cur_start;
		for (int i = 0; i < n; ++i)
		{
			if (!flg)
			{
				cnt++;
				last_finish = a[i][1];
				flg = 1;
			}
			else
			{
				if (a[i][0] >= last_finish)
				{
					cnt++;
					last_finish = a[i][1];
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}