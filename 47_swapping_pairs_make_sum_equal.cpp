// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/

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

int check_swap_possible(std::vector<int> v1, std::vector<int> v2, int s1, int s2)
{
	int l = min(v1.size(), v2.size());
	for (int i = 0; i < l; ++i)
	{

		int sum1 = s1 - v1[i] + v2[i], sum2 = s2 - v2[i] + v1[i];
		// bcout << sum1 << " " << sum2 << endl;
		if (sum1 == sum2)
			return 1;

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
		int n, m, sum1 = 0, sum2 = 0;
		cin >> n >> m;
		vector<int> a(n), b(m);

		for (long int i = 0; i < n; ++i)
		{
			cin >> a[i];
			sum1 += a[i];
		}
		for (long int i = 0; i < m; ++i)
		{
			cin >> b[i];
			sum2 += b[i];
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int ans;
		if (sum1 < sum2)
			ans = check_swap_possible(a, b, sum1, sum2);
		else
			ans = check_swap_possible(b, a, sum2, sum1);

		cout << ans << endl;
	}
	return 0;
}