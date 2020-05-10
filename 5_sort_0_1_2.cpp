// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long int n, tmp;
		cin >> n;
		
		vector<int> hash(3,0);
		for (long int j = 0; j < n; ++j)
		{
			cin >> tmp;
			hash[tmp]++;
		}
		for (long int j = 0; j < 3; ++j)
		{
			while(hash[j] != 0)
			{
				cout << j << " ";
				hash[j]--;
			}
		}
		cout << endl;
	}	
	return 0;
}