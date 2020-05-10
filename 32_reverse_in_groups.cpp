// https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0

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
		long int n, m;
		cin >> n >> m;
		vector<int> arr(n);
		
		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];	
		}

		long int s=m-1;
		while(s<n)
		{
			int steps = m;
			int i = s;
			while(steps)
			{
				cout << arr[i] << " ";
				i--;
				steps--;
			}
			s += m;
		}
		// there will be some ele which are never visited
		if(n%m)
		{
			s -= m;
			int steps = n-1-s;
			int i = n-1;
			while(steps)
			{
				cout << arr[i] << " ";
				i--;
				steps--;
			}
		}
		cout << endl;
	}	
	return 0;
}