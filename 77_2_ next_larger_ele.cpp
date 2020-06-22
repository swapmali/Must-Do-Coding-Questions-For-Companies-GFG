// https://practice.geeksforgeeks.org/problems/next-larger-element/0
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		std::vector<long long int> v(n); //, next_choosen(n, -1);
		int max_so_far = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			if (max_so_far < v[i])
				max_so_far = v[i];
		}
		//std::vector<long int> hash(max_so_far + 1, -1);
		unordered_map<long long int, long long int> m;
// 		for (int i = 0; i < n; ++i)
// 		{
// 			hash[v[i]] = i;
// 		}
		// cout << "hash: ";
		// print_vector(hash);

		std::vector<long long int> stack(n);
		int top = -1, cur;
		for (int i = 0; i < n; ++i)
		{
// 			cout << "\nv[i]:" << v[i] << endl;
			if (top == -1)
			{
				stack[++top] = v[i];
			}
			else if (stack[top] > v[i])
			{
				stack[++top] = v[i];
			}
			else
			{
				// cout << "top: " << top << endl;
				while (top > -1)
				{
					// 	cur = stack[top];
					// 	next_choosen[hash[cur]] = v[i];
					m[stack[top]] = v[i];
					top--;
					if (top > -1 && stack[top] < v[i])
					{
						// 		cur = stack[top];
						// 		next_choosen[hash[cur]] = v[i];
						m[stack[top]] = v[i];
						top--;
					}
					if (top == -1 or stack[top] > v[i])
					{
						stack[++top] = v[i];
						break;
					}
				}
			}
			/*
			cout << "next_choosen: ";
			print_vector(next_choosen);*/
// 			cout << "top:" << top << "  Stack: ";
// 			print_vector(stack);
		}
		while (top > -1)
		{
			m[stack[top]] = -1;
			top--;
		}

		for (long int i = 0; i < n; i++)
		{
			//  cout << "v[i]:" << v[i] << "    ";
			cout << m[v[i]] << " ";
		}
		cout << endl;


	}
	return 0;
}
