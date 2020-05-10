// https://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays/0

#include <bits/stdc++.h>
using namespace std;

void print_vector(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

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
		long int n;
		cin >> n;
		vector<int> a(n), b(n), c(2 * n);

		for (long int i = 0; i < n; ++i)	cin >> a[i];
		for (long int i = 0; i < n; ++i)	cin >> b[i];

		int i = 0, j = 0, k = 0, mid1 = (2 * n - 1) / 2, mid2 = (2 * n) / 2;
		while (i < n && j < n)
		{
			if (a[i] <= b[j])
			{
				c[k] = a[i];
				i++;
			}
			else
			{
				c[k] = b[j];
				j++;
			}
			k++;
		}

		while (i < n)
		{
			c[k] = a[i];
			i++;
			k++;
		}

		while (j < n)
		{
			c[k] = b[j];
			j++;
			k++;
		}

		cout << c[mid1] + c[mid2] << endl;

	}
	return 0;
}