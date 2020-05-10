// https://practice.geeksforgeeks.org/problems/key-pair/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long int n, x, flg = 0, cur_max = 0;
		cin >> n >> x;
		vector<int> arr(n);
		
		for (long int j = 0; j < n; ++j)
		{
			cin >> arr[j];		
			if(j && cur_max < arr[j])
			{
				cur_max = arr[j];
			}
		}

		std::vector<int> hash(cur_max+1, 0);
		
		for (long int j = 0; j < n; ++j)
		{
			hash[arr[j]]++;
		}

		for (long int j = 0; j < hash.size(); ++j)
		{
			cout << hash[j] << " ";
		}
		cout << endl;
		
		for (long int j = 0; j < n; ++j)
		{
			int cnt = hash[x-arr[j]];
			int diff = (x-arr[j]);
			if(diff < cur_max && diff > 0)
			{
				if( diff == arr[j] && cnt > 1)
				{
					cout << "Yes for "<< arr[j] << endl;
					flg = 1;
					break;
				}
				else if(diff != arr[j] && cnt)
				{
					cout << "Yes for "<< arr[j] << endl;
					flg = 1;
					break;
				}
			}
		}
		if(!flg)
		{
			cout << "No" << endl;
		}
	}	
	return 0;
}