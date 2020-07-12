// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// // using kruskals Greedy Algorithm
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
bool sort_by_weight (std::vector<int> &v1, std::vector<int> &v2)
{
    return v1[2] < v2[2];
}

// union - find algorithm to get to know if cycle is present in the cur graph by adding the cur edge or not
int find_parent(int node, vector<int> &parent_set)
{
    if (parent_set[node] == -1)
        return node;
    return find_parent(parent_set[node], parent_set);
}

void do_union(int src_parent, int new_parent, vector<int> &parent_set)
{
    parent_set[src_parent] = new_parent;
}

int is_cycle_present(int src, int dest, std::vector<int> &parent_set )
{
    int src_parent_set = find_parent(src, parent_set);
    int dest_parent_set = find_parent(dest, parent_set);

    // cycle present
    if (src_parent_set == dest_parent_set)
        return 1;

    // cycle not present : do union of src and dest sets
    do_union(src_parent_set, dest_parent_set, parent_set);
    return 0;
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V, int E, vector<vector<int>> &graph)
{
    vector< vector<int> > edges(E, vector<int> (3));
    int k = 0;
    // collect all only required edges in one vector
    for (int i = 0; i < graph.size(); ++i)
    {
        for (int j = 0; j < graph[0].size(); ++j)
        {
            if (graph[i][j] != INT_MAX && i < j)
            {
                edges[k][0] = i; edges[k][1] = j; edges[k][2] = graph[i][j];
                k++;
            }
        }
    }

    sort(edges.begin(), edges.end(), sort_by_weight);

    // required for checking if cycle present
    vector<int> parent_set(V, -1);
    int total_weight = 0;
    for (int i = 0; i < edges.size(); ++i)
    {
        int src = edges[i][0], dest = edges[i][1], weight = edges[i][2];
        // cout << src << " " << dest << " " << weight << " ";
        if (!is_cycle_present(src, dest, parent_set))
        {
            total_weight += weight;
        }
        // cout << total_weight << endl;
    }

    return total_weight;
}