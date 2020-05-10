// https://practice.geeksforgeeks.org/problems/finding-number/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int binarysearch(vector<int> arr, long int l, long int r, long int x)
{
	int mid = (l+r)/2;

	while(r>=l)
	{
		if(arr[mid] == x)
			return mid;

		if(arr[mid] > x)
			return binarysearch(arr, l, mid-1, x);
		
		return binarysearch(arr, mid+1, r, x);
	}

	return -1;
}

int reversebinarysearch(vector<int> arr, long int l, long int r, long int x)
{
	int mid = (l+r)/2;

	while(r>=l)
	{
		if(arr[mid] == x)
			return mid;

		if(arr[mid] > x)
			return binarysearch(arr, mid+1, r, x);
		
		return binarysearch(arr, l, mid-1, x);
	}

	return -1;
}


int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long int n, ind=-1, flg = 0, x, ans=-1;
		cin >> n;
		vector<int> arr(n);
		
		for (long int j = 0; j < n; ++j)
		{
			cin >> arr[j];		
		}
		
		cin >> x;

		for (long int j = 0; j < n; ++j)
		{
			if(arr[j] == x)
			{
				ans = j;
				flg = 1;
				break;
			}
		}

		cout << ans << endl;

		/*
		if(ind != -1)
		{		
			ans = binarysearch(arr, 0, ind-1, x);
			if(ans == -1)
			{
				ans = reversebinarysearch(arr, ind, n, x);
			}
		}
		else
		{
			if(arr[0] < arr[1])
				ans = binarysearch(arr, 0, n, x);
			else
				ans = reversebinarysearch(arr, 0, n, x);
		}

		cout << ans << endl;
		*/
	}	
	return 0;
}