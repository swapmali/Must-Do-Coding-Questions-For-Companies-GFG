// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		long int n, m, cnt = 0;
		cin >> n >> m;
		vector<int> a(n), b(m);
		
		for (long int i = 0; i < n; ++i)
		{
			cin >> a[i];	
		}

		for (long int i = 0; i < m; ++i)
		{
			cin >> b[i];	
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		/*
		cout << "A: " << endl;
		for (long int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl;
		cout << "B: " << endl;
		for (long int i = 0; i < m; ++i)
			cout << b[i] << " ";
		cout << endl;
		*/
		for (long int i = 0; i < n; ++i)
		{
			if(a[i] != 1)
			{
				int search = a[i];
				// to handle cases 2,3 & 2,4
				if(a[i] == 2)
					search = 4;

				std::vector<int> :: iterator upper;
				upper = upper_bound(b.begin(), b.end(), search);
				int ind = upper - b.begin();
				cnt += b.size()-ind;

				//cout << "for:" << a[i] << " cur cnt:" << b.size()-ind << "		tot_cnt:" << cnt << endl;
				//cout << cnt << endl;		
			}
		}	
		
		// to consider the case 3,2
		for (long int i = 0; i < n; ++i)
		{
			if(a[i] == 3 && binary_search(b.begin(), b.end(), 2))
			{
				std::vector<int> ::iterator upper, lower;
				lower = lower_bound(b.begin(), b.end(), 2);
				upper = upper_bound(b.begin(), b.end(), 2);
				cnt += (upper - lower);
			}
		}

		// to consider all cases of (x,1) where x > 1
		for (long int i = 0; i < m; ++i)
		{
			if(b[i] == 1)
			{
				std::vector<int> :: iterator upper;
				upper = upper_bound(a.begin(), a.end(), 1);
				int ind = upper - a.begin();
				cnt += a.size()-ind;	
			}
		}
		cout << cnt << endl;	
	}	
	return 0;
}