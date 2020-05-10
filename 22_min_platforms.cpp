// https://practice.geeksforgeeks.org/problems/minimum-platforms/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool sortval(const vector<int>& v1, const vector<int>& v2)
{
	return v1[0] < v2[0];
}

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, cnt=0, max_cnt = 0;
		cin >> n;
		vector < vector<int> > arr(2*n);
		
		for (int i = 0; i < 2*n; ++i)
		{
			arr[i].resize(2);
			cin >> arr[i][0];
			if(i<n)
				arr[i][1] = 0;	// arrival
			else
				arr[i][1] = 1;	// departure
		}

		//sort(arr.begin(), arr.end(), sortval);

		vector<int> arr_hash(2360,0), dep_hash(2360,0);

		for (int i = 0; i < 2*n; ++i)
		{
			if(arr[i][1])
			{
				// departure
				dep_hash[arr[i][0]]++;

			}
			else
			{
				// arrival
				arr_hash[arr[i][0]]++;
			}
		}

		/*
		// print hashes
		for (int i = 0; i < 2*n; ++i)
		{
			cout << arr[i][0] << " " << arr_hash[arr[i][0]] << " " << dep_hash[arr[i][0]] << endl;
			
		}
		*/
		for (int i = 0; i < 2360; ++i)
		{
			
			
			if(arr_hash[i]>0)
			{
				cnt += arr_hash[i];	
				if(max_cnt < cnt)
					max_cnt = cnt;
			}

			if(dep_hash[i]>0)
			{
				cnt -= dep_hash[i];
			}
			//cout << arr[i][0] << " " << arr[i][1] << " " << cnt << endl;
		}

		cout << max_cnt << endl;
	}	
	return 0;
}