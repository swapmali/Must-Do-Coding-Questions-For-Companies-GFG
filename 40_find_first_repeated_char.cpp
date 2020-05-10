// https://practice.geeksforgeeks.org/problems/find-first-repeated-character/0

#include <iostream>
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
		long int n;
		string str;
		cin >> str;
		// hash for storing first occurance in string
		vector<int> hash(26, 0), sec_occur_ind(26, -1);

		for (long int i = 0; i < str.length(); ++i)
		{
			int ind = str[i] - 97;
			hash[ind]++;
			if (hash[ind] == 2)
			{
				sec_occur_ind[ind] = i;
			}
		}

		// print_vector(hash);
		int flg = 0, min_sec_occ = INT_MAX, ans_int;
		for (long int i = 0; i < str.length(); ++i)
		{
			int ind = str[i] - 97;
			if (hash[ind] > 1)
			{
				if (sec_occur_ind[ind] < min_sec_occ)
				{
					min_sec_occ = sec_occur_ind[ind];
					ans_int = ind;
					flg = 1;
				}
			}
		}

		if (!flg)
			cout << -1 << endl;
		else
		{
			char c = ans_int + 97;
			cout << c << endl;
		}
	}
	return 0;
}