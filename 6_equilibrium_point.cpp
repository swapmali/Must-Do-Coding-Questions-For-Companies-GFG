// https://practice.geeksforgeeks.org/problems/equilibrium-point/0/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long int n, tmp, cur=0;
		cin >> n;
		std::vector<int> arr(n), fwd(n), bwd(n);
		
		for (long int j = 0; j < n; ++j)
		{
			cin >> arr[j];
			cur += arr[j];
			fwd[j] = cur;
		}

		cur = 0;
		for (long int j = n-1; j >= 0; --j)
		{
			cur += arr[j];
			bwd[j] = cur;
		}
		int flg = 0;
		for (long int j = 0; j < n; ++j)
		{
			if(fwd[j] == bwd[j])
			{
				cout << j+1 << endl;
				flg = 1;
				break;
			}
		}
		if(!flg)
			cout << -1 << endl;
		
	}	
	return 0;
}