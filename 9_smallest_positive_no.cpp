// https://practice.geeksforgeeks.org/problems/common-elements/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[j];
		}

		sort(arr.begin(), arr.end());
		
		for (int j = 0; j < n; ++j)
			cout << arr[j] << " ";
		cout << endl;
        
		std::vector<int>::iterator it = lower_bound(arr.begin(), arr.end(), 1);
		int ind = it - arr.begin();
		cout << arr[ind] << endl;

		int expected = 1, flg=0;
		for (int j = ind; j < n; ++j)
		{
		    while(arr[j] < expected)
				++j;
			cout << "checking for " << arr[j] << endl;

			if(arr[j] > expected)
			{
				cout << expected << endl;
				flg = 1;
				break;
			}
			expected++;
		}
		if(!flg)
			cout << expected++ << endl;

	}	
	return 0;
}