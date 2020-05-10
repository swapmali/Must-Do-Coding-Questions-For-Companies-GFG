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
		long int n;
		cin >> n;
		vector<int> arr(n);
		
		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];	
		}
		/*
		// code when relative order need not be same
		sort(arr.begin(), arr.end());

		for (long int i = 2; i < n; i += 2)
		{
			int temp = arr[i];
			arr[i] = arr[i-1];
			arr[i-1] = temp;
		}
		*/

		for (long int i = 0; i < n-1; ++i)
		{
			if(i%2==0 && arr[i] > arr[i+1])
			{
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
			else if(i%2==1 && arr[i] < arr[i+1])
			{
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}



		for (long int i = 0; i < n; ++i)
			cout << arr[i] << " ";
		cout << endl;

	}	
	return 0;
}