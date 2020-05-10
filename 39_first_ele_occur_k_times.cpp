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
		long int n, k, max_so_far = INT_MIN;
		cin >> n >> k;
		vector<int> arr(n);

		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			if (arr[i] > max_so_far)
				max_so_far = arr[i];
		}

		std::vector<int> hash(max_so_far + 1 , 0);

		for (long int i = 0; i < n; ++i)
		{
			hash[arr[i]]++;
		}

		int flg = 0;
		for (long int i = 0; i < n; ++i)
		{
			if (hash[arr[i]] == k)
			{
				cout << arr[i] << endl;
				flg = 1;
				break;
			}
		}
		if (!flg)
		{
			cout << "-1" << endl;
		}

	}
	return 0;
}