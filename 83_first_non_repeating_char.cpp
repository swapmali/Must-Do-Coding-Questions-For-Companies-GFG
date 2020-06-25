// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0
#include <bits/stdc++.h>
using namespace std;

void print_dq(deque<char> dq)
{
	cout << "\tdq: ";
	for (int i = 0; i < dq.size(); ++i)
	{
		char c = dq[i] + 97;
		cout << c << " ";
	}
	cout << endl;
}
void print_vector(vector<char>v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
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
		int n;
		cin >> n;
		vector<char> v(n);

		for (int i = 0; i < n; ++i)
			cin >> v[i];
		// print_vector(v);

		deque <char> dq;
		map<int, int> hash;
		for (int i = 0; i < n; i++)
		{
			int ind = v[i] - 97;

			if (!hash[ind])
			{
				dq.push_back(ind);
			}
			hash[ind]++;

			// get the non-repeated ele
			if (dq.empty())
			{
				cout << -1 << " ";
			}
			else
			{
				while (!dq.empty() && hash[dq.front()] > 1)
				{
					dq.pop_front();
				}

				if (dq.empty())
					cout << -1 << " ";
				else
				{
					char c =  dq.front() + 97;
					cout << c << " ";
				}
			}
			// print_dq(dq);
		}
		cout << endl;
	}
	return 0;
}
