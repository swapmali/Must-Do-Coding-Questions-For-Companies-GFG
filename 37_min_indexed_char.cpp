// https://practice.geeksforgeeks.org/problems/minimum-indexed-character/0

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
		string str, patt;
		cin >> str >> patt;
		// hash for storing first occurance in string
		vector<int> hash(26, -1);

		for (long int i = 0; i < str.length(); ++i)
		{
			int ind = str[i] - 97;
			// cout << ind << " ";
			if (hash[ind] == -1)
			{
				hash[ind] = i;
			}
		}

		int min_so_far = INT_MAX, flg = 0, min_char;
		for (int i = 0; i < patt.length(); ++i)
		{
			int ind = patt[i] - 97;
			if (hash[ind] != -1)
			{
				flg = 1;
				if (hash[ind] < min_so_far)
				{
					min_so_far = hash[ind];
					min_char = ind;
				}
			}
		}
		if (flg)
		{
			char c = min_char + 97;
			cout << c << endl;
		}
		else
		{
			cout << "$" << endl;
		}
		// print_vector(hash);

	}
	return 0;
}