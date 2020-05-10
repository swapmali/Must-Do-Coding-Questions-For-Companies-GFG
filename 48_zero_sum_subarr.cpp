// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0
#include <bits/stdc++.h>
using namespace std;

void print_vector(std::vector<long long int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
int calculate_cnt(vector<long long int> a, int n)
{
	int sum = 0, count = 0;
	unordered_map<int, int>ump;
	ump[0]++;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (ump.find(sum) != ump.end())
		{
			count += ump[sum];
		}
		ump[sum]++;
	}
	return count;
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
		long long int n, cnt = 0, max, min;
		cin >> n;
		vector<long long int> v(n), sum_arr(n);

		cin >> v[0];
		sum_arr[0] = v[0];
		min = max = v[0];

		for (long long int i = 1; i < n; ++i)
		{
			cin >> v[i];
		}
		cout << calculate_cnt(v, n) << endl;
	}
	return 0;
}