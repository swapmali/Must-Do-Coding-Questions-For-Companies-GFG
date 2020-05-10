#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int search(vector<int>nums, int target)
	{
		if (nums.size() == 0)
			return -1;
		else
			return binary_search_modified(nums, 0, nums.size() - 1, target);
	}

	int binary_search_modified(vector<int> nums, int l, int r, int target)
	{
		int mid = (l + r) / 2;
		// cout << "l:" << l << " r:" << r << " mid:" << mid << " nums[mid]: " << nums[mid]  << " target: " << target << endl;

		if (nums[mid] == target)
			return mid;
		else if (l <= r && l >= 0)
		{
			// pivot point on right side
			if (nums[l] <= nums[mid])
			{
				if (target > nums[mid])
					return binary_search_modified(nums, mid + 1, r, target);
				else
				{
					if (target >= nums[l])
						return binary_search_modified(nums, l, mid - 1, target);
					else
						return binary_search_modified(nums, mid + 1, r, target);
				}
			}
			// pivot point on left side
			else
			{
				if (target < nums[mid])
					return binary_search_modified(nums, l, mid - 1, target);
				else
				{
					if (target <= nums[r])
						return binary_search_modified(nums, mid + 1, r, target);
					else
						return binary_search_modified(nums, l, mid - 1, target);

				}
			}
		}
		return -1;
	}
};


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
		Solution s1;
		long int n, target;
		cin >> n;
		vector<int> arr(n);

		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		cin >> target;
		cout << s1.search(arr, target) << endl;

	}
	return 0;
}
