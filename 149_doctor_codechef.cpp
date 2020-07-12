// https://www.codechef.com/JULY20B/problems/DRCHEF
#include <bits/stdc++.h>
using namespace std;

void print_vector(vector< vector<int> > v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i][0] << " ";
	}
	cout << endl;
}

bool sortdesc( vector<int>&v1, vector<int>&v2)
{
	return v1[0] > v2[0];
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
		int n, x;
		cin >> n >> x;
		vector< vector<int> > p(n, vector<int>(2));

		for (int i = 0; i < n; ++i)
		{
			cin >> p[i][0];
			p[i][1] = p[i][0];
		}
		sort(p.begin(), p.end());
		// vector<int> org_p(p);

		int days = 0;
		int cures = x;
		print_vector(p);
		for (int i = 0; i < n; )
		{
			cout << "i:" << i << " day: " << days;
			if (p[i][0] * 2 > p[i][1])
				p[i][0] = p[i][1];
			else
				p[i][0] = p[i][0] * 2;
			cout << " cur_pop:" << p[i][0] << " cures:" << x;
			p[i][0] -= x;
			cout << " pop_after:" << p[i][0];
			cout << endl;
			print_vector(p);
			days++;
			x *= 2;
			if (p[i][0] <= 0)
			{
				i++;
				continue;
			}
		}
		cout << days << endl;
	}
	return 0;
}