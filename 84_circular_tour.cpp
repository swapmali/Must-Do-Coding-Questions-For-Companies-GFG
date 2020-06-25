// https://practice.geeksforgeeks.org/problems/circular-tour/1
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
	int petrol;
	int distance;
};

int tour(petrolPump [], int );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		petrolPump p[n];
		for (int i = 0; i < n; i++)
			cin >> p[i].petrol >> p[i].distance;
		cout << tour(p, n) << endl;
	}
}
// } Driver Code Ends

void print_dq(deque<int> dq)
{
	cout << "\tdq: ";
	for (int i = 0; i < dq.size(); ++i)
	{
		cout << dq[i] << " ";
	}
	cout << endl;
}

int tour(petrolPump p[], int n)
{
	deque <int> dq;
	int cur_petrol = 0;

	int j = 0, i, flg = 0, ans = -1;
	while (j < 2 * n)
	{
		i = j % n;
		// cout << "i:" << i << "\t";
		if (!dq.empty())
		{
			int ele = dq.front();
			if (i == ele)
			{
				ans = i;
				return ans;
			}
		}

		dq.push_back(i);
		cur_petrol += (p[i].petrol - p[i].distance);
		while (!dq.empty() && cur_petrol < 0)
		{
			int ele = dq.front();
			dq.pop_front();
			cur_petrol += (p[ele].distance - p[ele].petrol);
		}
		// print_dq(dq);
		j++;
	}
	return ans;
}
