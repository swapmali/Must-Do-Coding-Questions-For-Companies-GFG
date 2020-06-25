// https://practice.geeksforgeeks.org/problems/rotten-oranges/0
#include <bits/stdc++.h>
using namespace std;

// to replace 3's with 2's
void normalize(vector< vector<int> > &v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j] == 3)
				v[i][j] = 2;
		}
	}
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
		int r, c, last_dq_size;
		cin >> r >> c;
		last_dq_size = r * c;
		vector< vector<int> > v(r);
		deque < pair<int, int> > dq;
		stack < pair<int, int> > s;

		// taking input
		for (int i = 0; i < r; ++i)
		{
			v[i].resize(c);
			for (int j = 0; j < c; ++j)
			{
				cin >> v[i][j];

				// maintaining dq for fresh oranges
				if (v[i][j] == 1)
					dq.push_back(make_pair(i, j));
			}
		}

		int cnt = 1, x, y, flg = 0;
		while (!dq.empty() || !s.empty())
		{

			pair <int, int> temp;
			if (dq.empty())
			{
				// to replace 3's with 2's
				normalize(v);

				// insert all elements back to the dq from stack
				while (!s.empty())
				{
					temp = s.top();
					dq.push_back(temp);
					s.pop();
				}
				// which means there are unreachable oranges
				if (dq.size() >= last_dq_size)
				{
					cout << -1 << endl;
					flg = 1;
					break;
				}
				last_dq_size = dq.size();

				// increasing cnt after every iteration of emptying the dq
				cnt++;
			}

			pair <int, int> p = dq.front();
			x = p.first;
			y = p.second;

			// for each of the fresh arr checking if it is in unique dist with rotten orange
			if ((x + 1 < r && v[x + 1][y] == 2) || (y + 1 < c && v[x][y + 1] == 2) || (x - 1 >= 0 && v[x - 1][y] == 2) || (y - 1 >= 0 && v[x][y - 1] == 2))
			{
				// marking with 3 to indicate it is rotten in this iteration
				v[x][y] = 3;
			}
			else
			{
				// stack maintains fresh oranges which won't get rotten in this iteration
				s.push(p);
			}
			dq.pop_front();
		}
		if (!flg)
			cout << cnt << endl;
	}
	return 0;
}
