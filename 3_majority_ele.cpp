#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		long int n, tmp, ans=-1;
		cin >> n;
		std::vector<int> arr(n);
		for (long int j = 0; j < n; ++j)
			cin >> arr[j];
		sort(arr.begin(), arr.end());
		long int j=0, n_maj = n/2+1;
		while(j + n_maj-1 < n)
		{			
			if(arr[j] == arr[j+n_maj-1])
			{
				ans = arr[j];
				break;
			}
			j++;
		}
		cout << ans << endl;
	}	
	return 0;
}