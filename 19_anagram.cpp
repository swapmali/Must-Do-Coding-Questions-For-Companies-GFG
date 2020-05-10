// https://practice.geeksforgeeks.org/problems/anagram/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		string a,b;
		cin >> a >> b;
		vector<int> hash(26,0);
		
		for (long int j = 0; j < a.length(); ++j)
		{
			int ind = a[j] - 'a';
			hash[ind]++;
		}
		
		for (long int j = 0; j < b.length(); ++j)
		{
			int ind = b[j] - 'a';
			hash[ind]--;
		}
		
		int flg = 1;
		for (long int j = 0; j < 26; ++j)
		{
			if(hash[j] != 0)
			{
				flg = 0;
				break;
			}
		}
		if(!flg)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

	}	
	return 0;
}