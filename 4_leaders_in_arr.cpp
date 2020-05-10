// https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long int n;
		cin >> n;
		vector<int> arr(n), ans;
		
		for (long int j = 0; j < n; ++j)
			cin >> arr[j];

		long int cur_max = arr[n-1];
		for (long int j = n-1; j >= 0; --j)
		{
			if(arr[j] >= cur_max)
			{
				ans.push_back(arr[j]);
				cur_max = arr[j];
			}
		}

		for (long int j = ans.size()-1; j >= 0; --j)
			cout << ans[j] << " ";
		cout << endl;
	}	
	return 0;
}