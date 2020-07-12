// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0
#include <bits/stdc++.h>
using namespace std;

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

		vector<int> v{2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
		int cnt = 0, i = 0;
		while (n && i < v.size())
		{
			if (n / v[i] == 0)
			{
				i++;
				continue;
			}

			cnt = n / v[i];
			n = n % v[i];
			while (cnt--)
			{
				cout << v[i] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}