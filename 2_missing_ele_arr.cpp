#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		{
			long int n, tmp;
			cin >> n;
			std::vector<int> hash(n+1,0);
			for (long int j = 0; j < n-1; ++j)
			{
				cin >> tmp;
				hash[tmp] = 1;
			}
			for (long int j = 1; j < hash.size(); ++j)
			{
				if(hash[j] == 0)
				{
					cout << j << endl;
					break;
				}
			}
		}	
	return 0;
}