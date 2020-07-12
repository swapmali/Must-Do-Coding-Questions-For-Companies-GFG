// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0

#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int>v, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

// max heap functions
void maxheapify_up(vector<int>&v, int &heap_size, int ind)
{
	if (ind < 0)
		return;

	int left = 2 * ind + 1;
	int right = left + 1;
	int greatest = ind;

	if (left < heap_size && v[left] > v[greatest])
		greatest = left;
	if (right < heap_size && v[right] > v[greatest])
		greatest = right;

	// if added no is greater than its parent
	if (greatest != ind)
	{
		int temp = v[greatest];
		v[greatest] = v[ind];
		v[ind] = temp;
	}
	// heapify on its parent
	maxheapify_up(v, heap_size, (ind + 1) / 2 - 1);
}

void maxheapify_down(vector<int>&v, int &heap_size, int ind)
{
	int left = 2 * ind + 1;
	int right = left + 1;
	int greatest = ind;

	if (left < heap_size && v[left] > v[greatest])
		greatest = left;
	if (right < heap_size && v[right] > v[greatest])
		greatest = right;

	// if added no is greater than its parent
	if (greatest != ind)
	{
		int temp = v[greatest];
		v[greatest] = v[ind];
		v[ind] = temp;
		// heapify on its child
		maxheapify_down(v, heap_size, greatest);
	}

}

// min heap functions
void minheapify_up(vector<int>&v, int heap_size, int ind)
{
	if (ind < 0)
		return;

	int left = 2 * ind + 1;
	int right = left + 1;
	int smallest = ind;

	if (left < heap_size && v[left] < v[smallest])
		smallest = left;
	if (right < heap_size && v[right] < v[smallest])
		smallest = right;

	// if added no is greater than its parent
	if (smallest != ind)
	{
		int temp = v[smallest];
		v[smallest] = v[ind];
		v[ind] = temp;
	}
	// heapify on its parent
	minheapify_up(v, heap_size, (ind + 1) / 2 - 1);
}

void minheapify_down(vector<int>&v, int &heap_size, int ind)
{
	int left = 2 * ind + 1;
	int right = left + 1;
	int smallest = ind;

	if (left < heap_size && v[left] < v[smallest])
		smallest = left;
	if (right < heap_size && v[right] < v[smallest])
		smallest = right;

	// if added no is greater than its parent
	if (smallest != ind)
	{
		int temp = v[smallest];
		v[smallest] = v[ind];
		v[ind] = temp;

		// heapify on its child
		minheapify_down(v, heap_size, smallest);
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

	int n;
	cin >> n;
	vector<int> maxheap(n), minheap(n);
	int maxheap_size = 0, minheap_size = 0;

	while (n--)
	{
		int tmp;
		cin >> tmp;
		// for the first time
		if (!maxheap_size || maxheap[0] > tmp)
		{
			maxheap[maxheap_size] = tmp;
			maxheap_size++;
			maxheapify_up(maxheap, maxheap_size, maxheap_size - 1);
		}
		else
		{
			minheap[minheap_size] = tmp;
			minheap_size++;
			minheapify_up(minheap, minheap_size, minheap_size - 1);
		}

		// we want to maintain same elements i.e. first half in maxheap
		//and other half in min heap
		if (abs(maxheap_size - minheap_size) > 1)
		{
			// maxheap has more elements
			if (maxheap_size > minheap_size)
			{
				// delete max from maxheap and add into minheap
				int ele = maxheap[0];
				maxheap[0] = maxheap[maxheap_size - 1];
				maxheap_size--;
				maxheapify_down(maxheap, maxheap_size, 0);

				// add to minheap
				minheap[minheap_size] = ele;
				minheap_size++;
				minheapify_up(minheap, minheap_size, minheap_size - 1);
			}
			else     //minheap has more elements
			{
				// delete min from minheap and add into maxheap
				int ele = minheap[0];
				minheap[0] = minheap[minheap_size - 1];
				minheap_size--;
				minheapify_down(minheap, minheap_size, 0);

				// add to maxheap
				maxheap[maxheap_size] = ele;
				maxheap_size++;
				maxheapify_up(maxheap, maxheap_size, maxheap_size - 1);
			}
		}
		cout << "maxheap: ";
		print_vector(maxheap, maxheap_size);
		cout << "minheap: ";
		print_vector(minheap, minheap_size);

		// if current stream is of even length
		if ((maxheap_size + minheap_size) % 2 == 0)
			cout << (minheap[0] + maxheap[0]) / 2 << endl;
		else if (maxheap_size > minheap_size)
			cout << maxheap[0] << endl;
		else
			cout << minheap[0] << endl;
	}

	// print_vector(minheap);
	return 0;
}