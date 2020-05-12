// https://practice.geeksforgeeks.org/problems/remove-duplicates/0

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
	string tmp;
	getline(cin, tmp);
	while (t--)
	{
		string s;
		getline(cin, s);
		cout << s << endl;
		vector<int> hash(256, 0);

		for (int i = 0; i < s.length(); ++i)
		{
			if (!hash[s[i]])
				cout << s[i];
			hash[s[i]]++;
		}
		cout << endl;
	}
	return 0;
}