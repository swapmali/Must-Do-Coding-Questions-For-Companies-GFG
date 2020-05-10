// https://practice.geeksforgeeks.org/problems/binary-search/1

#include <bits/stdc++.h>
using namespace std;

int binary_search(std::vector<int> a, int l, int r, int search)
{
	int mid = (l + r) / 2;

	if (a[mid] == search)
		return mid;
	else if (l >= 0 && l <= r)
	{
		if (a[mid] < search)
			return binary_search(a, mid + 1, r, search);
		else
			return binary_search(a, l, mid - 1, search);
	}
	return -1;
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
		long int n, search;
		cin >> n;
		vector<int> arr(n);

		for (long int i = 0; i < n; ++i)	cin >> arr[i];
		cin >> search;
		cout << binary_search(arr, 0, n - 1, search) << endl;
	}
	return 0;
}