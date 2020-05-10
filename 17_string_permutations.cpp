// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		cout << s << " ";
		while(next_permutation(s.begin(), s.end()))
		{
			cout << s << " ";
		}
		cout << endl;
	}	
	return 0;
}