// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int get_digits(int n)
{
	if(n/10 == 0)
		return 1;
	else if(n/100 == 0)
		return 2;
	else
		return 3;
}

int concate_to_output(string *output, int n, int size)
{
	int divide;
	while(size)
	{
		if(size == 3)
			divide = 100;
		else if(size == 2)
			divide = 10;
		else
			divide = 1;

		int digit = n/divide;
		char dig = digit ;
		*output += dig;
		size--;
	}
}



int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
		long int n;
		cin >> n;
		
		string output;
		vector<int> arr(n);
		vector < vector < vector<int> > >  hash(10);
		
		for (long int i = 0; i < 10; ++i)
			hash[i].resize(3);

		for (long int i = 0; i < n; ++i)
		{
			cin >> arr[i];	
		}

		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());

		for (long int i = 0; i < n; ++i)
		{	
			int digits = get_digits(arr[i]);
			if(digits == 1)
			{
				hash[arr[i]][0].push_back(arr[i]);
			}
			else if(digits == 2)
			{
				int ind = arr[i]/10;
				hash[ind][1].push_back(arr[i]);
			}
			else
			{
				int ind = arr[i]/100;
				hash[ind][2].push_back(arr[i]);
			}
		}

		// print hash
		cout << "Hash: " << endl;
		for (long int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < hash[i][0].size(); ++j)
			{
				cout << hash[i][0][j] << " ";
			}
			cout << "		";

			for (int j = 0; j < hash[i][1].size(); ++j)
			{
				cout << hash[i][1][j] << " ";
			}
			cout << "		";

			for (int j = 0; j < hash[i][2].size(); ++j)
			{
				cout << hash[i][2][j] << " ";
			}
			cout << "\n";
		}

		cout << "done printing" << endl;
		
		cout << "size of hash [5][2]:" << hash[5][2].size();

		// main logic
		for (long int i = 1; i < 10; ++i)
		{
			cout << "i: " << i << endl;
			int is_avail_0 = hash[i][0].size();
			int is_avail_1 = hash[i][1].size();
			int is_avail_2 = hash[i][2].size();
			
			cout << "Entering while loop" ;
			while(is_avail_0 >0 or is_avail_1 > 0 or is_avail_2 >0)
			{	
				cout << "Entered " ;
				// get second digit of all max of length 2,3 digit numbers starting with i
				int second_digit_len_2 = -1, second_digit_len_3 = -1 , third_digit_len_3 = -1;
				
				if(is_avail_1 > 0)
					second_digit_len_2 = hash[i][1][0] % 10;

				if(is_avail_2 > 0)
				{
					int temp = hash[i][2][0];
					third_digit_len_3 = temp%10;
					temp /= 10;
					second_digit_len_3 = temp%10;
				}


				
				// logic 1
				if(second_digit_len_3 > second_digit_len_2)
				{

					if(is_avail_0 > 0)
					{	
						if(second_digit_len_3 > i)
						{
							//concate_to_output(&output, hash[i][2][0], 3);
							cout << hash[i][2][0];
							hash[i][2].erase(hash[i][2].begin());
						}
						else if(second_digit_len_3 < i)
						{
							cout << hash[i][0][0];
							hash[i][0].erase(hash[i][0].begin());
						}
						else
						{
							if(third_digit_len_3 >= i)
							{
								cout << hash[i][2][0];
								hash[i][2].erase(hash[i][2].begin());
							}
							else
							{
								cout << hash[i][0][0];
								hash[i][0].erase(hash[i][0].begin());
							}
						}
					}
					else
					{
						cout << hash[i][2][0];
						hash[i][2].erase(hash[i][2].begin());
					}
				}
				// logic 2
				else if(second_digit_len_2 > second_digit_len_3)
				{
					cout << "checkpoint 2" ;
					if(is_avail_0 > 0)
					{	
						if(second_digit_len_2 >= i)
						{
							//concate_to_output(&output, hash[i][2][0], 3);
							cout << hash[i][1][0];
							hash[i][1].erase(hash[i][1].begin());
						}
						else
						{
							cout << hash[i][0][0];
							hash[i][0].erase(hash[i][0].begin());
						}
					}
					else
					{
						cout << hash[i][1][0];
						hash[i][1].erase(hash[i][1].begin());
					}
				}
				// logic 3
				// if they are equal
				else
				{
					cout << "checkpoint 3" ;
					if(is_avail_0 > 0)
					{	
						if(second_digit_len_2 >= i)
						{
							// compare 3rd digit from len 3 no.
							if(third_digit_len_3 >= i)
							{
								cout << hash[i][2][0];
								hash[i][2].erase(hash[i][2].begin());
							}
							else
							{
								cout << hash[i][1][0];
								hash[i][1].erase(hash[i][1].begin());
							}
						}
						else if(second_digit_len_2 < i)
						{
							cout << hash[i][0][0];
							hash[i][0].erase(hash[i][0].begin());	
						}
					}
					else
					{
						if(third_digit_len_3 >= i)
						{
							cout << hash[i][2][0];
							hash[i][2].erase(hash[i][2].begin());
						}
						else
						{
							cout << hash[i][1][0];
							hash[i][1].erase(hash[i][1].begin());
						}
					}
				}
			}

		}

		// print hash
		cout << "Hash: " << endl;
		for (long int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < hash[i][0].size(); ++j)
			{
				cout << hash[i][0][j] << " ";
			}
			cout << "		";

			for (int j = 0; j < hash[i][1].size(); ++j)
			{
				cout << hash[i][1][j] << " ";
			}
			cout << "		";

			for (int j = 0; j < hash[i][2].size(); ++j)
			{
				cout << hash[i][2][j] << " ";
			}
			cout << "\n";
		}

		

	}	
	return 0;
}