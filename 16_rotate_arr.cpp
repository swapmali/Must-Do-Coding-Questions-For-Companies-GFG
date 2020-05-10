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
		long int n, d;
		cin >> n >> d;
		d= d%n;
		vector<int> arr(n);
		
		for (long int j = 0; j < n; ++j)
			cin >> arr[j];		

		for (long int j = d; j < n; ++j)
			cout << arr[j] << " ";

		for (long int j = 0; j < d; ++j)	
			cout << arr[j] << " ";
		cout << endl;	
	}	
	return 0;
}