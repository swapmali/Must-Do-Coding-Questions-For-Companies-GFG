//https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		unsigned long long int n;
		unsigned long long int max_so_far = 0, max_so_far2 = 0;
		cin >> n;

		unsigned long long int a[n], b[n];

		for (unsigned long long int i = 0; i < n; ++i)
		{
			cin >> a[i];
			if (max_so_far < a[i])
			{
				max_so_far = a[i];
			}
		}
		for (unsigned long long int i = 0; i < n; ++i)
		{
			cin >> b[i];
			if (max_so_far2 < b[i])
			{
				max_so_far2 = b[i];
			}
		}

		// O(n Logn) solution
		sort(a, a + n);
		sort(b, b + n);
		int flg = 0;
		for (unsigned long long int i = 0; i < n; ++i)
		{
			if (a[i] != b[i])
			{
				flg = 1;
				break;
			}
		}
		if (!flg)
			cout << 1 << endl;
		else
			cout << 0 << endl;

		// O(n) solution : but SEG FAULT presentL: not found
		/*if (max_so_far != max_so_far2)
			cout << 0 << endl;
		else
		{
			unsigned long long int hash1[max_so_far + 1] = {0}, hash2[max_so_far + 1] = {0};
			for (unsigned long long int i = 0; i < n; ++i)
				hash1[a[i]]++;

			for (unsigned long long int i = 0; i < n; ++i)
				hash2[b[i]]++;

			for (unsigned long long int i = 0; i < max_so_far; ++i)
				cout << hash1[i] << " " << hash2[i] << endl;


			int flg = 0;
			for (unsigned long long int i = 0; i < n; ++i)
			{
				if (hash1[a[i]] != hash2[a[i]])
				{
					flg = 1;
					break;
				}
			}

			if (!flg)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}*/

	}
	return 0;
}