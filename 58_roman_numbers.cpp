// https://practice.geeksforgeeks.org/problems/roman-number-to-integer/0

#include <bits/stdc++.h>
using namespace std;

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
		vector<int> roman_values(27, -1);
		/*roman values for storing values
			I = 1
			v = 5
			X = 10
			L = 50
			C = 100
			D = 500
			M = 1000 */

		roman_values[9] = 1;
		roman_values[22] = 5;
		roman_values[24] = 10;
		roman_values[12] = 50;
		roman_values[3] = 100;
		roman_values[4] = 500;
		roman_values[13] = 1000;

		int value = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			//cout << s[i] - 64 << endl;
			int val1 = roman_values[s[i] - 64], val2 = roman_values[s[i + 1] - 64];
			if (i + 1 < s.length() &&  val1 < val2)
			{
				value += (val2 - val1);
				i++;
			}
			else
			{
				value += val1;
			}
		}
		cout << value << endl;
	}
	return 0;
}