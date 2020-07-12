// https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
#include <bits/stdc++.h>
using namespace std;


bool partition_sum(vector<int> a, int n)
{
	int total_sum = 0;
	for (int i = 0; i < n; ++i)
		total_sum += a[i];

	if (total_sum % 2)
		return false;

	int k = total_sum / 2;
	// vector <vector <bool> > SS(n + 1, vector<bool>(k + 1));
	bool SS[n + 1][k + 1];

	// initialize first col to true
	// with 0 elements sum 0 is always possible
	for (int i = 0; i < n + 1; ++i)
		SS[i][0] = true;

	// initialize first row to false
	// with 0 elements sum>0 is not possible
	for (int j = 1; j < k + 1; ++j)
		SS[0][j] = false;


	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < k + 1; ++j)
		{
			if (j >= a[i - 1])
			{
				// when we not include cur element or we include it
				SS[i][j] = (SS[i - 1][j] || SS[i - 1][j - a[i - 1]]);
			}

			else
			{
				// we are not able to include it
				SS[i][j] = SS[i - 1][j];
			}
		}
	}

	// print_2d(SS);
	return SS[n][k];
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
		vector<int> a(n);

		for (int i = 0; i < n; ++i)
			cin >> a[i];

		if (partition_sum(a, n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}