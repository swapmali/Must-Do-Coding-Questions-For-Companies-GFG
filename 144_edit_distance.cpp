// https://practice.geeksforgeeks.org/problems/edit-distance/0
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

int min(int x, int y, int z)
{
	return x > y ? (y > z ? z : y) : (x > z ? z : x);
}

int min_edit_distance(string a, string b, int n, int m)
{
	// C[i][j] represents Cost required to convert
	// string a from starting till index i
	// string b from starting till index j
	vector< vector<int> > C(n + 1, vector<int> (m + 1));

	for (int i = 0; i < n + 1; ++i)
		C[i][0] = i;
	for (int i = 0; i < m + 1; ++i)
		C[0][i] = i;
	C[0][0] = 0;

	// main code
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 1; j < m + 1; ++j)
		{
			if (a[i - 1] == b[j - 1])
				C[i][j] = C[i - 1][j - 1];
			else
				C[i][j] = 1 + min( C[i - 1][j], C[i][j - 1], C[i - 1][j - 1]);
		}
	}
	print_2d(C);
	return C[n][m];
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
		string a, b;
		cin >> a >> b;
		cout << min_edit_distance(a, b, n, m) << endl;
	}
	return 0;
}