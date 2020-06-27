// https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;

    return temp;
}

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

void connect(struct Node *p);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */


void printSpecial(Node *root)
{
    if (root == NULL)
        return;

    Node* next_root = NULL;

    while (root != NULL)
    {
        cout << root->data << " ";

        if ( root->left && (!next_root) )
            next_root = root->left;
        else if ( root->right && (!next_root)  )
            next_root = root->right;

        root = root->nextRight;
    }

    printSpecial(next_root);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        connect(root);
        printSpecial(root);
        cout << endl;
        inorder(root);
        cout << endl;
    }
    return 0;
}

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
void connect(Node *root)
{
    queue <Node*> q1, q2;
    q1.push(root);

    Node *cur_node, *next_node, *node;
    while (!q1.empty())
    {
        while (!q1.empty())
        {
            cur_node = q1.front();
            q1.pop();

            if (!q1.empty())
                next_node = q1.front();
            else
                next_node = NULL;

            q2.push(cur_node -> left);
            q2.push(cur_node -> right);
            cur_node -> nextRight = next_node;
        }

        while (!q2.empty())
        {
            node = q2.front();
            q2.pop();

            if (node != NULL)
                q1.push(node);
        }

    }

}
