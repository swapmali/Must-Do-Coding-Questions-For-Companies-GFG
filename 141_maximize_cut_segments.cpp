// https://practice.geeksforgeeks.org/problems/cutted-segments/0
#include <bits/stdc++.h>
using namespace std;

void print_2d(vector<vector<int> > v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int maximize_cut_seg(int n, vector<int> a)
{
	vector <vector <int> > mcs(4, vector<int> (n + 1));
	int max_cut_seg = 0;
	// initialize first row to 0's
	for (int i = 0; i < n + 1; ++i)
		mcs[0][i] = 0;
	// initialize first col to 0's
	for (int i = 0; i < 4; ++i)
		mcs[i][0] = 0;

	for (int i = 1; i < 4; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			// if rod size is less than curr valid cut
			if (j < a[i - 1])
				mcs[i][j] = mcs[i - 1][j];
			else
			{
				// if rod size is same as curr valid cut size
				if (j == a[i - 1])
				{
					mcs[i][j] = 1;
				}
				else
				{
					// after cutting the rod size j with curr cut a[i-1]
					// if remaining rod size is a valid cuttable
					if (mcs[i][j - a[i - 1]] > 0)
						mcs[i][j] = max(mcs[ i ][ j - a[i - 1] ] + 1, mcs[i - 1][j]);
					else
						mcs[i][j] = max(mcs[i - 1][j], 0);
				}
			}

			// for our main rod size maintain max_cut_seg found so far
			if (j == n && mcs[i][j] > max_cut_seg)
				max_cut_seg = mcs[i][j];
		}
	}
	// print_2d(mcs);
	return max_cut_seg;

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
		// rod length
		int n;
		cin >> n;
		vector<int> cuts(3);
		for (int i = 0; i < 3; ++i)
			cin >> cuts[i];
		sort(cuts.begin(), cuts.end());
		cout << maximize_cut_seg(n, cuts) << endl;
	}
	return 0;
}