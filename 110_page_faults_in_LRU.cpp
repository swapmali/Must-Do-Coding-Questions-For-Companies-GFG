// https://practice.geeksforgeeks.org/problems/page-faults-in-lru/0

#include <bits/stdc++.h>
using namespace std;

int is_present_in_cache(deque <int> dq, int page_no)
{
	for (int i = 0; i < dq.size(); ++i)
	{
		if (dq[i] == page_no)
			return i;
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
		int n, m;
		cin >> n;
		vector<int> pages(n);

		for (int i = 0; i < n; ++i)
			cin >> pages[i];

		cin >> m;

		deque <int> dq;
		int page_faults = 0;

		for (int i = 0; i < n; ++i)
		{
			int ind = is_present_in_cache(dq, pages[i]);
			// if page is not present in cache
			if (ind == -1)
			{
				if (dq.size() >= m)
					dq.pop_front();

				dq.push_back(pages[i]);
				page_faults++;
			}
			else	// page is present in cache
			{
				dq.erase(dq.begin() + ind);
				dq.push_back(pages[i]);
			}
		}

		cout << page_faults << endl;
	}
	return 0;
}