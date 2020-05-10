// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0

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
		int n, cnt = 1 , max_cnt = 0, max_from_arr = 0;
		cin >> n;
		vector<int> arr(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		if (n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		sort(arr.begin(), arr.end());

		// print_vector(arr);
		for (int i = 0; i < n - 1; ++i)
		{
			if (arr[i + 1] - arr[i] == 0)
			{
				continue;
			}
			else if (arr[i + 1] - arr[i] != 1)
			{
				cnt = 1;
			}
			else
			{
				cnt++;
			}
			if (cnt > max_cnt)
				max_cnt = cnt;
			cout << i << " cnt:" << cnt << endl;
		}
		cout << max_cnt << endl;
	}
	return 0;
}