// https://practice.geeksforgeeks.org/problems/immediate-smaller-element/0

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

		for (long int j = 0; j < n-1; ++j)
		{
			if(arr[j] > arr[j+1])
				cout << arr[j+1] << " ";
			else
				cout << -1 << " ";
		}
		cout << -1 << endl;
	}	
	return 0;
}