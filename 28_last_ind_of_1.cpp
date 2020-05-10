// https://practice.geeksforgeeks.org/problems/last-index-of-1/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		int ind = -1;
		string s;
		cin >> s;

		for (long int i = 0; i < s.length(); ++i)
		{
			if(s[i] == '1')
				ind = i;
		}
		cout << ind << endl;
	}	
	return 0;
}