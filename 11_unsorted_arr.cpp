// https://practice.geeksforgeeks.org/problems/unsorted-array/0/

#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long int n, tmp;
		cin >> n;
		vector<int> arr(n), fwd(n,0), bwd(n,0);
		
		for (long int j = 0; j < n; ++j)
			cin >> arr[j];		

		long int cur_max = arr[0], cur_min = arr[n-1];
		for (long int j = 1; j < n-1; ++j)
		{
			if(arr[j] >= cur_max)
			{
				cur_max = arr[j];
				fwd[j] = 1;
			}
		}

		for (long int j = n-2; j > 0; --j)
		{
			if(arr[j] <= cur_min)
			{
				cur_min = arr[j];
				bwd[j] = 1;
			}
		}

		int flg = 0;
		for (long int j = 0; j < n; ++j)
		{
			if(fwd[j] == 1 && bwd[j] == 1)
			{
				cout << arr[j] << endl;
				flg = 1;
				break;
			}
		}
		if(!flg)
			cout << -1 << endl;
	}	
	return 0;
}