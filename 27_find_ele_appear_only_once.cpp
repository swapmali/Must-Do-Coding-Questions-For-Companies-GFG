// https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		long int n;
		cin >> n;
		vector<int> arr(n);
		
		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];	
		}

		std::vector<int> hash(arr[arr.size()-1]+1, 0);

		for (long int i = 0; i < n; ++i)
		{
			hash[arr[i]]++;
		}


		for (long int i = 0; i < hash.size(); ++i)
		{
			if(hash[i] == 1)
			{
				cout << i << endl;
				break;
			}
		}
	}	
	return 0;
}