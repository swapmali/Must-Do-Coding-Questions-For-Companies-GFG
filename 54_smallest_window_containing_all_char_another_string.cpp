// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0/
// NOT-COMPLETE
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

int find_next_ind(string s, int cur_ind, int l, int r, int &sec_min, std::vector<int> hasht)
{
	int next_ind = -1;
	sec_min = -1;
	for (int i = l + 1; i <= s.length(); ++i)
	{	int ind = s[i] - 97;
		if (ind == cur_ind && next_ind == -1)
		{
			next_ind = i;
		}
		else if (hasht[ind] && ind != cur_ind && sec_min == -1)
		{
			sec_min = i;
		}
	}
	return next_ind;
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
		string s, t;
		cin >> s >> t;
		vector<int> hasht(26, 0), window_hash(26, 0), first_ind_t_in_s(26, -1), cur;

		for (long int i = 0; i < t.length(); ++i)
		{
			int ind = t[i] - 97;
			hasht[ind]++;
		}

		// cout << "hasht: ";
		// print_vector(hasht);

		int min = INT_MAX, max = INT_MIN;
		for (int i = 0; i < s.length(); ++i)
		{
			int ind = s[i] - 97;
			if (hasht[ind] && first_ind_t_in_s[ind] == -1)
			{
				first_ind_t_in_s[ind] = i;
				if (i < min)
					min = i;
				if (i > max)
					max = i;
			}
		}

		// check all of char in t are present in s
		int flg = 0;
		for (int i = 0; i < t.length(); ++i)
		{
			int ind = t[i] - 97;
			if (first_ind_t_in_s[ind] == -1)
			{
				flg = 1;
				break;
			}
		}

		if (flg)
			cout << -1 << endl;
		else
		{
			for (int i = min; i <= max; ++i)
			{
				int ind = s[i] - 97;
				// if cur char is indeed present in string t (which is required to be present in s).
				if (hasht[ind])
					window_hash[ind]++;
			}



			// cout << "first_ind_t_in_s: ";
			// print_vector(first_ind_t_in_s);

			int l = min, r = max, min_window_so_far = r - l + 1, sec_min;
			cout << "min:" << min << " max:" << max << " min_window_so_far:" << r - l + 1 << endl;

			// cout << "window_hash: ";
			// print_vector(window_hash);

			// cout << "check_all_present: " << check_all_present(s, l, r, hasht) << endl;
			int itr = 0;
			while (r < s.length() && l < r && l >= 0)
			{

				cout << "l:" << l << " r:" << r << endl;
				int ind = s[l] - 97;

				// if cur char is indeed present in string t (which is required to be present in s).
				if (hasht[ind])
				{
					int next_ind = find_next_ind(s, ind, l, r, sec_min, hasht);
					// cout << "next_ind:" << next_ind << " sec_min:" << sec_min << endl;
					if (next_ind < r)
					{
						l = next_ind;

					}
					else if (next_ind > r)
					{
						// get min ind from cur window excluding of cur searched char
						l = sec_min;
						r = next_ind;
					}


					if (min_window_so_far > r - l + 1)
					{
						min_window_so_far = r - l + 1;
						min = l;
						max = r;
					}
				}

				//print_vector(window_hash);
				cout << "min_window_so_far: " << min_window_so_far  << " min:" << min << " max:" << max << endl;


			}
			for (int i = min; i <= max; ++i)
			{
				cout << s[i];
			}
			cout << endl;
		}
	}
	return 0;
}