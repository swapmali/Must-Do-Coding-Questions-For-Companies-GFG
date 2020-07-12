// https://practice.geeksforgeeks.org/problems/find-first-set-bit/0
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
		std::vector<int> v;
		while (n > 0)
		{
			int bit = n % 2;
			v.push_back(bit);
			n = n / 2;
		}


		for (auto it = v.rbegin(); it != v.rend() ; ++it)
		{
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}