// https://practice.geeksforgeeks.org/problems/uncommon-characters/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		long int n;
		string str1, str2;
		cin >> str1 >> str2;

		// hash for storing first occurance in string
		vector<int> hash1(26, 0), hash2(26, 0);

		for (long int i = 0; i < str1.length(); ++i)
		{
			int ind = str1[i] - 97;
			hash1[ind] = 1;
		}

		for (long int i = 0; i < str2.length(); ++i)
		{
			int ind = str2[i] - 97;
			hash2[ind] = 1;
		}
		for (int i = 0; i < 26; ++i)
		{
			if (!hash1[i] || !hash2[i])
			{
				if (hash1[i] || hash2[i])
				{
					char c = i + 97;
					cout << c ;
				}
			}
		}
		cout << endl;
	}
	return 0;
}