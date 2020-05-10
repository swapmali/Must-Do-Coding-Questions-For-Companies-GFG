#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool sortval(string s1, string s2)
{
	return stoi(s1+s2) > stoi(s2+s1);
}

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<string> v(n);
		
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];	
		}

		sort(v.begin(), v.end(), sortval);

		for (int i = 0; i < n; ++i)
		{
			cout << v[i];
		}
		cout << endl;
	}	
	return 0;
}