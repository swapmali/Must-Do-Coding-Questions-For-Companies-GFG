// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector <int> verticalOrder(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    string  tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        // string c;
        // getline(cin,c);
        Node* root = buildTree(s);

        vector <int> res = verticalOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child
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

int get_height(struct Node* root)
{
    if (root == NULL)
        return 0;

    return 1 + max(get_height(root->left), get_height(root->right));
}


void get_min_max(struct Node* root, int horizontal_dist, int &minimum, int &maximum)
{
    if (root == NULL)
        return;

    if (horizontal_dist > maximum)
        maximum = horizontal_dist;

    if (horizontal_dist < minimum)
        minimum = horizontal_dist;

    get_min_max(root -> left, horizontal_dist - 1, minimum, maximum);
    get_min_max(root -> right, horizontal_dist + 1, minimum, maximum);

}

void get_vertical_order(struct Node* root, vector< vector< vector<int> > > &vertical_order, int horizontal_dist, int level, int ind)
{
    if (root == NULL)
        return;

    vertical_order[horizontal_dist + ind][level].push_back(root->data);

    get_vertical_order(root -> left, vertical_order, horizontal_dist - 1, level + 1, ind);
    get_vertical_order(root -> right, vertical_order, horizontal_dist + 1, level + 1, ind);
}

// root: root node of the tree
vector<int> verticalOrder(Node *root)
{
    vector<int> v;

    int minimum = INT_MAX, maximum = INT_MIN;
    get_min_max(root, 0, minimum, maximum);
    // cout << minimum << " " << maximum << endl;

    int height = get_height(root);
    // cout << "height:" << height << endl;

    vector< vector< vector<int> > > vertical_order(maximum + abs(minimum) + 1);
    for (int i = 0; i < vertical_order.size(); ++i)
    {
        vertical_order[i].resize(height);
    }

    get_vertical_order(root, vertical_order, 0, 0, abs(minimum));


    // cout << "vertical_order: ";
    for (int i = 0; i < vertical_order.size(); ++i)
    {
        for (int j = 0; j < vertical_order[i].size(); ++j)
        {
            for (int k = 0; k < vertical_order[i][j].size(); ++k)
            {
                // cout << vertical_order[i][j][k] << " ";
                v.push_back(vertical_order[i][j][k]);
            }
        }
        // cout << endl;
    }
    return v;
}