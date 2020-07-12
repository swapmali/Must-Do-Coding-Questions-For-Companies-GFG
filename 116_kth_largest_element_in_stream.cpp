// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0

#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int>v, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void minheapify_up(vector<int> &minheap, int size, int ind)
{
	if (ind < 0)
		return;

	int left = 2 * ind + 1;
	int right = left + 1;
	int smallest = ind;

	if (left < size && minheap[left] < minheap[smallest])
		smallest = left;
	if (right < size && minheap[right] < minheap[smallest])
		smallest = right;

	if (smallest != ind)
	{
		int t = minheap[ind];
		minheap[ind] = minheap[smallest];
		minheap[smallest] = t;
	}
	minheapify_up(minheap, size, (ind + 1) / 2 - 1);
}

void minheapify_down(vector<int> &minheap, int size, int ind)
{
	int left = 2 * ind + 1;
	int right = left + 1;
	int smallest = ind;

	if (left < size && minheap[left] < minheap[smallest])
		smallest = left;
	if (right < size && minheap[right] < minheap[smallest])
		smallest = right;

	if (smallest != ind)
	{
		int t = minheap[ind];
		minheap[ind] = minheap[smallest];
		minheap[smallest] = t;

		minheapify_down(minheap, size, smallest);
	}
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
		int k, n;
		cin >> k >> n;
		vector<int> minheap(k);
		int size = 0;

		for (int i = 0; i < k; ++i)
		{
			int temp;
			cin >> temp;
			minheap[size] = temp;
			size++;
			minheapify_up(minheap, size, size - 1);

			if (i < k - 1)
				cout << -1 << " ";
			else
				cout << minheap[0] << " ";
		}
		// cout << "\nminheap:";
		// print_vector(minheap, size);

		for (int i = k; i < n; ++i)
		{
			int temp;
			cin >> temp;

			// cur ele belongs to k-largest elements
			if (minheap[0] < temp)
			{
				minheap[0] = temp;
				minheapify_down(minheap, size, 0);
			}
			// cout << "\nminheap:";
			// print_vector(minheap, size);
			cout << minheap[0] << " ";
		}
		cout << endl;

	}
	return 0;
}