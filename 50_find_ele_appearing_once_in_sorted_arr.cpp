// https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void print_vector(std::vector<int> v)
{
	for (ll int i = 0; i < v.size(); ++i)
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
		ll int n, max = INT_MIN;
		cin >> n;
		std::vector<ll int > arr(n);
		for (ll int i = 0; i < n; ++i)
			cin >> arr[i];

		std::vector<int> hash(arr[arr.size() - 1] + 1, -1);

		for (ll int i = 0; i < n; ++i)
		{
			hash[arr[i]] = i;
		}
		// print_vector(hash);

		for (ll int i = 0; i < hash.size(); ++i)
		{
			if (hash[i] != -1)
			{
				if (hash[i] % 2 == 0)
				{
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}