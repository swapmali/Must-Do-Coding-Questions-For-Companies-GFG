// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/
// NOT RUN ABort Signal Error
#include <bits/stdc++.h>
using namespace std;

void print_vector(std::vector<long long int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int my_binary_search(vector<long long int> v, int l, int r, long long int num)
{
	if (l > r)
		return -1;

	int mid = (l + r) / 2;
	if (v[mid] == num)
		return mid;
	else if (v[mid] > num)
		return my_binary_search(v, l, r - 1, num);
	else
		return my_binary_search(v, mid + 1, r, num);
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
		int n, m;
		cin >> n >> m;
		vector<long long int> a(n), b(m), sum_a(n), sum_b(n);

		long long int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			sum += a[i];
			sum_a[i] = sum;
		}
		sum = 0;
		for (int i = 0; i < m; ++i)
		{
			cin >> b[i];
			sum += b[i];
			sum_b[i] = sum;
		}

		// repeatitions vector contains
		// 0:repeated_no, 1:index_in_a 2:index_in_b
		vector < vector<long long int> > repeatitions;
		for (int i = 0; i < a.size(); ++i)
		{
			int ind = my_binary_search(b, 0, m - 1, a[i]);
			// means a[i] is repeated in both a & b
			if ( ind != -1)
			{
				vector<long long int> v(3);
				v[0] = a[i]; v[1] = i; v[2] = ind;
				repeatitions.push_back(v);
			}
		}

		if (!repeatitions.size())
		{
			cout << max(sum_a[n - 1], sum_b[m - 1]);
			continue;
		}
		print_vector(sum_a);
		print_vector(sum_b);
		cout << endl;
		for (int i = 0; i < repeatitions.size(); ++i)
		{
			cout << repeatitions[i][0] << " " << repeatitions[i][1] << " " << repeatitions[i][2] << endl;
		}

		long long int max_balls = 0;
		for (int i = 0; i <= repeatitions.size(); ++i)
		{
			long long int cur_sum_a, cur_sum_b;
			// for first repeatition
			if (!i)
			{
				cur_sum_a = sum_a[repeatitions[i][1]];
				cur_sum_b = sum_b[repeatitions[i][2]];
			}
			else if (i < repeatitions.size())
			{
				cur_sum_a = sum_a[repeatitions[i][1]] - sum_a[repeatitions[i - 1][1]];
				cur_sum_b = sum_b[repeatitions[i][2]] - sum_b[repeatitions[i - 1][2]];
			}
			else	// for elements in each arrs could be present even after last repeatition index
			{
				cur_sum_a = sum_a[n - 1] - sum_a[repeatitions[i - 1][1]];
				cur_sum_b = sum_b[m - 1] - sum_b[repeatitions[i - 1][2]];
			}

			if ( cur_sum_a <= cur_sum_b)
			{
				max_balls += cur_sum_b;
			}
			else
			{
				max_balls += cur_sum_a;
			}
		}
		cout << max_balls << endl;
	}
	return 0;
}