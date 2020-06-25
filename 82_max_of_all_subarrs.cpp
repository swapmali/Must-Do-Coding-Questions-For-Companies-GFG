// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
#include <bits/stdc++.h>
using namespace std;

void print_dq(deque<int> dq)
{
	for (int i = 0; i < dq.size(); ++i)
	{
		cout << dq[i] << " ";
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
		int n, k;
		cin >> n >> k;
		vector<int> v(n);

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		deque <int> dq;

		for (int i = 0; i < k; i++)
		{
			if (dq.empty())
				dq.push_back(v[i]);
			else
			{
				while (!dq.empty() && dq.back() < v[i])
				{
					dq.pop_back();
				}
				dq.push_back(v[i]);
			}
		}
		cout << dq.front() << " ";

		int pos = 0;
		for (int i = k; i < n; i++)
		{
			// cout << "\tdq:";
			// print_dq(dq);
			while (!dq.empty() && dq.back() < v[i])
			{
				dq.pop_back();
			}
			dq.push_back(v[i]);

			int max = dq.front();
			if (max == v[pos])
			{
				dq.pop_front();
				max = dq.front();
			}
			pos++;

			cout << max << " ";
		}
		cout << endl;
	}
	return 0;
}
