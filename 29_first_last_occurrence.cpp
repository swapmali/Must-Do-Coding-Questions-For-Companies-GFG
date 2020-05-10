// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		long int n, x, lind, uind;
		cin >> n;
		vector<int> arr(n);
		
		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];	
		}
		cin >> x;

		std::vector<int> :: iterator lower, upper;
		lower = lower_bound(arr.begin(), arr.end(), x);
		lind = lower - arr.begin();

		upper = upper_bound(arr.begin(), arr.end(), x);
		uind = upper - arr.begin() -1;

		if(lind > uind)
			cout << "-1" << endl;
		else
			cout << lind << " " << uind << endl;
	}	
	return 0;
}