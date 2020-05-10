// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

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

void countDistinct(int a[], int k, int n)
{
	int max = *max_element(a, a + n);
	vector<int> hash(max + 1);
	int cnt_repeats = 0;

	for (int i = 0; i < k; ++i)
	{
		hash[a[i]]++;
		if (hash[a[i]] > 1)
			cnt_repeats++;
	}
	// cout << cnt_repeats << endl;
	cout << k - cnt_repeats << " ";

	for (int i = 1; i <= n - k; ++i)
	{
		hash[a[i - 1]]--;
		if (hash[a[i - 1]])
			cnt_repeats--;

		hash[a[i + k - 1]]++;
		if (hash[a[i + k - 1]] > 1)
			cnt_repeats++;

		cout << k - cnt_repeats << " ";
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
		long int n, k;
		cin >> n >> k;
		int arr[n];

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		countDistinct(arr, k , n);
		cout << endl;
	}
	return 0;
}