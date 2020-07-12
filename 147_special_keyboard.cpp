// https://practice.geeksforgeeks.org/problems/special-keyboard/0
#include <bits/stdc++.h>
using namespace std;

int prints(int n)
{
	if (n < 7)
		return n;
	std::vector<int> T(n + 1, 0);

	for (int i = 0; i < 7; ++i)
		T[i] = i;

	for (int i = 7; i < n + 1; ++i)
	{
		int cnt = 2;
		int max_chars = 0;
		for (int j = i - 3; j > 1; --j)
		{
			max_chars = max(max_chars, T[j] * cnt);
			cnt++;
		}
		T[i] = max_chars;
	}
	return T[n];
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
		if (n > 75)
			cout << -1 << endl;
		else
			cout << prints(n) << endl;
	}
	return 0;
}