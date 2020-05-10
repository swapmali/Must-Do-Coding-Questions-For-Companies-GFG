// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long int n, tmp, flg = 0;
		cin >> n;
		vector<int> arr(n);
		
		for (long int j = 0; j < n; ++j)
		{
			cin >> arr[j];
			if(j>0 && arr[j-1] < arr[j])
				flg = 1;
		}
		long int j = 0;
		if(!flg)
			cout << "No Profit" << endl;
		else
		{
			while(j < n-1)
			{
				while(arr[j] >= arr[j+1] && j < n-1)
				{
					j++;
				}
				if(arr[j] < arr[j+1] && j < n-1)
					cout << "(" << j << " ";

				while(arr[j] <= arr[j+1] && j < n-1)
				{
					j++;
				}
				if(arr[j] > arr[j+1] && j < n-1)
				{
					cout << j << ") ";
				}
				else if (j == n-1 && arr[j-1] < arr[j])
				{
					cout << j << ") ";
				}

			}
			cout << endl;
		}
	}	
	return 0;
}