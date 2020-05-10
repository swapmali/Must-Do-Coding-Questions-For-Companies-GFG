// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long int n, zcnt=0, ocnt=0, out=0;
		cin >> n;
		vector<int> arr(n), zeros(n), ones(n);
		
		for (long int j = 0; j < n; ++j)
			cin >> arr[j];

		for (long int j = 0; j < n; ++j)
		{
			if(arr[j] == 0)
				zcnt++;
			else
				ocnt++;
			zeros[j] = zcnt;
			ones[j] = ocnt;
		}

		for (long int j = 0; j < n; ++j)
			cout << zeros[j] << " ";
		cout << endl;

		for (long int j = 0; j < n; ++j)
			cout << ones[j] << " ";
		cout << endl << endl;


		long int l=0, r=n-1, ans;
		zcnt=0, ocnt=0;
		while(l<r)
		{

			// to check if there are same no of zeros & ones in current subarr
			if(l!=0)
			{
				zcnt = zeros[r] - zeros[l-1];
				ocnt = ones[r] - ones[l-1];
				if(zcnt == ocnt)
				{
					out = zcnt;
					cout <<"done: " << l << " " << r << " " << " cnt: " << zcnt<< endl;
					break;
				}
			}
			else
			{
				zcnt = zeros[r];
				ocnt = ones[r];
				if(zcnt == ocnt)
				{
					cout <<"done: " << l << " " << r << " " << " cnt: " << zcnt<< endl;
					out = zcnt;
					break;
				}
			}


			cout << l << " " << r << " " << zcnt << " " << ocnt << endl; 
			// change subarr 
			if(zcnt > ocnt)
			{
				
				if(arr[l] == 0)
				{
					l++;
				}
				else if(arr[r] == 0)
				{
					r--;
				}
				else
				{
					l++;
				}
			}
			else
			{
				if(arr[l] == 1)
				{
					l++;
				}
				else if(arr[r] == 1)
				{
					r--;
				}
				else
				{
					l++;
				}
			}

		}
		ans = out *2;



		l=0, r=n-1;
		zcnt=0, ocnt=0;
		while(l<r)
		{

			// to check if there are same no of zeros & ones in current subarr
			if(l!=0)
			{
				zcnt = zeros[r] - zeros[l-1];
				ocnt = ones[r] - ones[l-1];
				if(zcnt == ocnt)
				{
					out = zcnt;
					cout <<"done: " << l << " " << r << " " << " cnt: " << zcnt<< endl;
					break;
				}
			}
			else
			{
				zcnt = zeros[r];
				ocnt = ones[r];
				if(zcnt == ocnt)
				{
					cout <<"done: " << l << " " << r << " " << " cnt: " << zcnt<< endl;
					out = zcnt;
					break;
				}
			}


			cout << l << " " << r << " " << zcnt << " " << ocnt << endl; 
			// change subarr 
			if(zcnt > ocnt)
			{
				
				if(arr[l] == 0)
				{
					l++;
				}
				else if(arr[r] == 0)
				{
					r--;
				}
				else
				{
					r--;
				}
			}
			else
			{
				if(arr[l] == 1)
				{
					l++;
				}
				else if(arr[r] == 1)
				{
					r--;
				}
				else
				{
					r--;
				}
			}

		}
		if(ans > out*2)
		{
			cout << ans;
		}
		else
		{
			cout << out * 2;
		}

	}	
	return 0;
}