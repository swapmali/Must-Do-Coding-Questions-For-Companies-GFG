// https://practice.geeksforgeeks.org/problems/relative-sorting/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_vector(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << i << ": " << v[i] << endl;
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
		long int n, m, cur_max = 0;
		cin >> n >> m;
		vector<int> arr(n), a2(m);

		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			if (arr[i] > cur_max)
				cur_max = arr[i];
		}

		for (long int i = 0; i < m; ++i)
		{
			cin >> a2[i];
		}

		std::vector<int> hash(cur_max + 1, 0);

		for (long int i = 0; i < n; ++i)
		{
			hash[arr[i]]++;
		}

		// print_vector(hash);

		for (int i = 0; i < m; ++i)
		{
			while (hash[a2[i]])
			{
				cout << a2[i] << " ";
				hash[a2[i]]--;
			}
		}
		for (int i = 0; i < hash.size(); ++i)
		{
			while (hash[i])
			{
				cout << i << " ";
				hash[i]--;
			}
		}
		cout << endl;
		// print_vector(hash);
	}
	return 0;
}