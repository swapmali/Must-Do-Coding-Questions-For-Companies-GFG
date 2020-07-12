// https://practice.geeksforgeeks.org/problems/max-length-chain/1
#include <bits/stdc++.h>
using namespace std;

int mlc(vector< pair<int, int> > p, int n)
{
	sort(p.begin(), p.end());
	std::vector<int> v(n, 1);
	int max_length = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = i; j >= 0; --j)
		{
			if (p[j].second < p[i].first)
			{
				v[i] = max(1 + v[j], v[i]);
				if (v[i] > max_length)
					max_length = v[i];
			}
		}
	}
	return max_length;
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
		vector< pair<int, int> > p(n);

		for (int i = 0; i < n; ++i)
			cin >> p[i].first >> p[i].second;


		cout << mlc(p, n) << endl;

	}
	return 0;
}