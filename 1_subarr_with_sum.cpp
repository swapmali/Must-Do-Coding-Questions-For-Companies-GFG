#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() 
{
	int t;
	
	cin >> t;
	for(int i=0;i<t;i++)
	{
	    long int n, s;
	    cin >> n >> s;
	    vector <int> v(n);
	    for(long int j=0;j<n;j++)
	       cin >> v[j];
	   
	   long int start=0, j=1, cur_sum = v[0], flg=0;
	   cout << cur_sum << " " << start << " " << j << endl;
	   for(j=1; j <= n; j++)
	   {
	   		if(cur_sum > s && start <= j)
	   		{
	   			cur_sum -= v[start];
	   			start++;
	   			j--;
	   		}
	   		else if(cur_sum == s)
	   		{	
	   			flg=1;
	   			break;
	   		}
	   		else if(cur_sum < s && j<n)
	   		{
	   			cur_sum += v[j];
	   		}
	   		cout << cur_sum << " " << start << " " << j << endl;   
	   }

	   if(flg)
	   {
	   		cout << "Main Ans: " << cur_sum << " " << start+1 << " " << j << endl;   
	   }
	   else
	   		cout << -1 << endl;
	}
	return 0;
}