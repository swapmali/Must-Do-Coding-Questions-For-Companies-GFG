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
		long int n1, n2, n3, max=0;
		cin >> n1 >> n2 >> n3;
		vector<long int> arr1(n1), arr2(n2), arr3(n3);
		
		for (long int j = 0; j < n1; ++j)
		{
			cin >> arr1[j];
			if(max < arr1[j])
				max = arr1[j];
		}

		for (long int j = 0; j < n2; ++j)
		{
			cin >> arr2[j];
			if(max < arr2[j])
				max = arr2[j];
		}

		for (long int j = 0; j < n3; ++j)
		{
			cin >> arr3[j];
			if(max < arr3[j])
				max = arr3[j];
		}

		std::vector<int> hash(max+1,0);
		for (long int j = 0; j < n1; ++j)
		{
			if(hash[arr1[j]] == 0)
				hash[arr1[j]]++;
		}
		for (long int j = 0; j < n2; ++j)
		{
			if(hash[arr2[j]] == 1)
				hash[arr2[j]]++;
		}
		for (long int j = 0; j < n3; ++j)
		{
			if(hash[arr3[j]] == 2)
				hash[arr3[j]]++;
		}

		int flg = 0;
		for (long int j = 0; j < max+1; ++j)
		{
			if(hash[j] == 3)
			{
				cout << j << " ";
				flg = 1;
			}	
		}
		if(!flg)
			cout << -1;
		cout << endl;
	}	
	return 0;
}