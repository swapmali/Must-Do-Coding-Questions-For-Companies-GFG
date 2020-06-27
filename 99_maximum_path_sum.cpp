// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int maxPathSum(Node *);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        cout << maxPathSum(root) << "\n";
    }
    return 0;
}// } Driver Code Ends


/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
// my_code
int max_sum;

int get_max_path_sum(Node* root)
{
    if (root == NULL)
        return 0;

    int left_sum = get_max_path_sum(root -> left), right_sum = get_max_path_sum(root -> right);

    if (root -> left && root -> right)
    {
        if (max_sum < (left_sum + right_sum + root->data))
        {
            max_sum = left_sum + right_sum + root->data;
        }
    }

    // cout << "for:" << root->data << " max_sum:" <<  max_sum << " left_sum:" << left_sum << " right_sum:" << right_sum << endl;

    if (root->left == NULL && root -> right == NULL)
        return root->data;

    if (root->right == NULL)
        return root->data + left_sum;

    if (root -> left == NULL)
        return root->data + right_sum;

    return root -> data + max(left_sum , right_sum);
}



int maxPathSum(Node* root)
{
    max_sum = INT_MIN;
    get_max_path_sum(root);
    // cout << max_sum << endl;
    return max_sum;
}