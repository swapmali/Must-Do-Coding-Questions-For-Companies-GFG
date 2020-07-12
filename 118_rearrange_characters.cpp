// https://practice.geeksforgeeks.org/problems/rearrange-characters/0
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
		string s;
		cin >> s;
		vector<int> hash(26, 0);

		for (int i = 0; i < s.length(); ++i)
		{
			hash[s[i] - 97]++;
		}
		std::vector<int> v;
		for (int i = 0; i < 26; ++i)
		{
			if (hash[i])
				v.push_back(hash[i]);
		}
		sort(v.begin(), v.end(), greater<int>());

		// print_vector(hash);
		// print_vector(v);
		int val = v[0];
		for (int i = 1; i < v.size(); ++i)
		{
			val -= v[i];
		}
		if (val <= 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}