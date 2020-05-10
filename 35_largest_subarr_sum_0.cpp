// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int a[], int n);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends

/*You are required to complete this function*/
int maxLen(int a[], int n) {
    int max_len = 0, max_left_sum = a[0], min_left_sum = a[0];
    vector <int> left_sum(n);

    left_sum[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        left_sum[i] = left_sum[i - 1] + a[i];

        if (left_sum[i] == 0)
            max_len = i + 1;

        if (left_sum[i] > max_left_sum)
            max_left_sum = left_sum[i];
        else if (left_sum[i] < min_left_sum)
            min_left_sum = left_sum[i];
    }
    if (min_left_sum < 0)
    {
        max_left_sum -= min_left_sum;
        for (int i = 0; i < n; i++)
        {
            left_sum[i] -= min_left_sum;
        }
    }
    // storing 1st index of left sums
    vector<int> hash(max_left_sum + 1, -1);

    for (int i = 0; i < n; i++)
    {
        int ind = left_sum[i];
        if (hash[ind] == -1)
        {
            hash[ind] = i;
        }
        else
        {
            int cur_len = i - hash[ind];
            if (cur_len > max_len)
                max_len = cur_len;
            //cout << "max_len:" << max_len << "\n" << endl;
        }
    }
    return max_len;
}
