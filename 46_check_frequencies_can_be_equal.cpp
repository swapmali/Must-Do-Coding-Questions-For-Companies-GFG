// https://practice.geeksforgeeks.org/problems/check-frequencies/0
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

void print_2d_vector(vector< vector<int> > v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
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
		string s;
		cin >> s;
		vector<int> hash(26, 0);

		for (int i = 0; i < s.length(); ++i)
		{
			int ind = s[i] - 97;
			hash[ind]++;
		}

		sort(hash.begin(), hash.end());
		// print_vector(hash);

		std::vector<int>:: iterator upper;
		upper = upper_bound(hash.begin(), hash.end(), 0);
		int ind = upper - hash.begin();
		// cout << ind << endl;

		int uniq_values = 1, max_diff = 0, change_ind;
		for (int i = ind; i < 25; ++i)
		{
			int cur_diff = hash[i + 1] - hash[i];
			if ( cur_diff != 0)
			{
				uniq_values++;
				change_ind = i + 1;
				if (cur_diff > max_diff)
				{
					max_diff = cur_diff;
				}
			}
		}
		// cout << "uniq_values:" << uniq_values << " max_diff:" << max_diff << endl;
		if (uniq_values <= 1)
		{
			cout << 1 << endl;
		}
		else if (uniq_values > 2)
		{
			cout << 0 << endl;
		}
		else if (uniq_values = 2 && max_diff == 1)
		{

			int min_change = change_ind - ind > 26 - change_ind ? 26 - change_ind : change_ind - ind;
			// cout << "change_ind:" << change_ind  << " min_change:" << min_change << endl;
			if (min_change < 2)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else
		{
			cout << 0 << endl;
		}

	}
	return 0;
}