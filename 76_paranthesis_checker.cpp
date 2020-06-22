// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
#include <bits/stdc++.h>
using namespace std;

void print_vector(std::vector<char> v)
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
		string s;
		cin >> s;
		vector<char> stack(s.length());
		int top = -1;
		for (int i = 0; i < s.length(); ++i)
		{
			if (top == -1)
			{
				stack[++top] = s[i];
			}
			else
			{
				if (s[i] == '}' && stack[top] == '{')
				{
					top--;
				}
				else if (s[i] == ')' && stack[top] == '(')
				{
					top--;
				}
				else if (s[i] == ']' && stack[top] == '[')
				{
					top--;
				}
				else
				{
					// push
					stack[++top] = s[i];
				}
			}
			// print_vector(stack);
		}
		if (top == -1)
			cout << "balanced" << endl;
		else
			cout << "not balanced" << endl;

	}
	return 0;
}
