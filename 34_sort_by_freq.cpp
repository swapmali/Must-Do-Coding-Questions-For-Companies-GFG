// https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0

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

void print_2d_vector(vector< vector<int> > v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << i << ": ";
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
		long int n, cur_max = 0;
		cin >> n;
		vector<int> arr(n);

		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			if (arr[i] > cur_max)
				cur_max = arr[i];
		}

		std::vector<int> hash(cur_max + 1, 0);

		for (long int i = 0; i < n; ++i)
		{
			hash[arr[i]]++;
		}

		// print_vector(hash);

		int max = *max_element(hash.begin(), hash.end());
		vector< vector<int> > hash2_on_cnts(max + 1);

		for (int i = 0; i < hash.size(); ++i)
		{
			if (hash[i])
			{
				hash2_on_cnts[hash[i]].push_back(i);
			}
		}

		// print_2d_vector(hash2_on_cnts);

		for (int i = hash2_on_cnts.size() - 1; i > 0 ; --i)
		{
			for (int j = 0; j < hash2_on_cnts[i].size(); ++j)
			{
				int freq = i;
				while (freq)
				{
					cout << hash2_on_cnts[i][j] << " ";
					freq--;
				}
			}
		}
		cout << endl;
	}
	return 0;
}