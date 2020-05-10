// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		long int n,m;
		cin >> n >> m;
		vector<long int> a(n), b(m);
		
		for (long int i = 0; i < n; ++i)
		{
			cin >> a[i];	
		}

		for (long int i = 0; i < m; ++i)
		{
			cin >> b[i];	
		}
		long int i=0, j=0;
		while(i < n && j < m)
		{
			if(a[i] <= b[j])
			{
				cout << a[i] << " ";
				i++;
			}
			else
			{
				cout << b[j] << " ";
				j++;
			}
		}

		while(i<n)
		{
			cout << a[i] << " ";
			i++;
		}

		while(j<m)
		{
			cout << b[j] << " ";
			j++;
		}

		cout << endl;
	}	
	return 0;
}