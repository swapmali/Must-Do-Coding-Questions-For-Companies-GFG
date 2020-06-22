// https://practice.geeksforgeeks.org/problems/next-larger-element/0
#include <bits/stdc++.h>
using namespace std;

void print_vector(std::vector<long int> v)
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
		int n;
		cin >> n;
		std::vector<long int> v(n), next_choosen(n, -1);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		for (int i = n - 1; i >= 0; --i)
		{

			if (i == n - 1)
			{
				next_choosen[i] = -1;
			}
			else
			{
				if (v[i] < v[i + 1])
				{
					next_choosen[i] = v[i + 1];
				}
				else
				{
					int j = i + 1;
					while (j < n)
					{
						if (v[i] < next_choosen[j])
						{
							next_choosen[i] = next_choosen[j];
							break;
						}
						j++;
					}
				}
			}

		}
		print_vector(next_choosen);
	}
	return 0;
}
