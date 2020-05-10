// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--)
	{
		long int n, m, cur_min = INT_MAX, val;
		cin >> n;

		vector<int> arr(n);
		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];	
		}
		cin >> m;

		sort(arr.begin(), arr.end());

		for (long int i = 0; i < n-m+1; ++i)
		{
			//cout << "comparing locations " << i+m-1 << " & " << i << endl;
			val = arr[i+m-1] - arr[i];
			if(val < cur_min)
			{
				cur_min = val;
			}
		}
		cout << cur_min << endl;
	}	
	return 0;
}