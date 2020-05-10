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
		long int n, flg=0;
		cin >> n;
		vector<int> arr(n);
		
		for (long int j = 0; j < n; ++j)
			cin >> arr[j];		
		sort(arr.begin(), arr.end());
		for (long int j = 0; j < n; ++j)
		{
			if(!flg)
			{	
				for (long int k = j+1; k < n; ++k)
				{
					double search = sqrt(arr[j] * arr[j] + arr[k] * arr[k]);
					cout << search << endl;
					if(binary_search(arr.begin()+k+1, arr.end(), search))
					{
						cout << "Yes" << endl;
						cout << arr[j] << " " << arr[k] << " " << search << endl;
						flg = 1;
						break;
					}
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