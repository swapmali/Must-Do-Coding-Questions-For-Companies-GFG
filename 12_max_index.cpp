// https://practice.geeksforgeeks.org/problems/maximum-index/0

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
		vector<long long int> arr(n);
		
		for (long int j = 0; j < n; ++j)
		{
			cin >> arr[j];
		}
        int cur_max = 0;
		for (long int j = 0; j < n; ++j)
		{
			for (long int k = n-1; k >= j; --k)
			{
				if(arr[j] <= arr[k])
				{
					//cout << k-j << endl;
					if (cur_max < k-j)
						cur_max = k-j;
					break;
				}
			}
		}
		cout << cur_max << endl;
	}	
	return 0;
}
