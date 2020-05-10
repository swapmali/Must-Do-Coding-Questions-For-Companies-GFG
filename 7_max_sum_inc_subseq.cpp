// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/
// not complete
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
		vector<int> arr(n);
		
		for (long int j = 0; j < n; ++j)
			cin >> arr[j];		

		long int l = 0, r = 1, cur_sum = arr[0], max_so_far = arr[0];
		while(l <= r && r < n)
		{
			if(arr[l] < arr[r])
			{
				cur_sum += arr[r];
				if(max_so_far < cur_sum)
				{
					max_so_far = cur_sum;	
				}
				
				r++;
				l++;
				while(arr[l] > arr[r] && l < r)
					l++;
				
			}
			else if(arr[l] > arr[r])
			{
				//cur_sum -= arr[r-1];
				r++;
				if(l==0)
				{
					l++;
					cur_sum = arr[l];
				}
			}
		}

	}	
	return 0;
}