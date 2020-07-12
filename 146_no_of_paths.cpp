// https://practice.geeksforgeeks.org/problems/number-of-paths/0
#include <bits/stdc++.h>
using namespace std;

int nop(int x, int y)
{
	if (x == 1 && y == 1)
		return 1;

	int left = 0, top = 0;

	if (x - 1 >= 0)
		top = nop(x - 1, y);
	if (y - 1 >= 0)
		left = nop(x, y - 1);

	return left + top;
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
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		cout << nop(n, m) << endl;

	}
	return 0;
}