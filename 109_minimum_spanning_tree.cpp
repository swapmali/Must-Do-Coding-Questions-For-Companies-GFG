// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// using Prims Greedy Algorithm

#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// my code

// returns vertex which is having min key at that point
// and not selected to be in MST previously.
int get_min_key(vector<int> key, vector<int> mstset)
{
    int min_key = INT_MAX, min_index;
    for (int i = 0; i < key.size(); ++i)
    {
        if (!mstset[i] && key[i] < min_key)
        {
            min_key = key[i];
            min_index = i;
        }
    }
    return min_index;
}



// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V, int E, vector<vector<int>> &graph)
{
    std::vector<int> mstset(V, 0); // stores vertices not included in MST
    std::vector<int> key(V, INT_MAX); // stores min weights of node
    // std::vector<int> parent; // stores MST

    int total_weight = 0;

    key[0] = 0;
    for (int i = 0; i < V; ++i)
    {


        int u = get_min_key(key, mstset);
        mstset[u] = 1;
        total_weight += key[u];


        // add all adjacent vertices to u which are
        // not selected to be part of MST previously
        for (int v = 0; v < V; ++v)
        {
            // updated key distance should be less than the
            // existing key distance wrt some other vertex
            if (!mstset[v] && key[v] > graph[u][v])
            {
                key[v] = graph[u][v];
            }
        }

    }
    return total_weight;
}