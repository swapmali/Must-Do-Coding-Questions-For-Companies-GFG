// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		long int n, cur_max = 0, max_so_far = 0;
		cin >> n;
		vector<int> arr(n);
		
		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];	
		}
		/*
		int i=0;
		while(i<n)
		{
			rotate(arr.begin()+i, arr.begin()+arr.size()-1 , arr.end());	
			i += 2;
		}
		*/
		int l=0, r=n-1;
		while(l<r)
		{
			cout << arr[r] << " " << arr[l] << " ";
			l++;
			r--;
		}
		if(l==r)
		{
			cout << arr[l];
		}
		cout << endl;
	}	
	return 0;
}