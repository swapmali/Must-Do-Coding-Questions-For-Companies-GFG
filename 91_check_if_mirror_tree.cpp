// https://practice.geeksforgeeks.org/problems/symmetric-tree/1
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
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
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
bool isSymmetric(struct Node* root);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        if (isSymmetric(root))
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends


/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
/*void get_inorder(struct Node* root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    get_inorder(root -> left, inorder);
    inorder.push_back(root -> data);
    get_inorder(root -> right, inorder);
}

void get_preorder(struct Node* root, vector<int> &preorder)
{
    if (root == NULL)
        return;

    preorder.push_back(root -> data);
    get_preorder(root -> left, preorder);
    get_preorder(root -> right, preorder);
}
*/
void get_mirror_tree(struct Node* root)
{
    if (root == NULL)
        return;

    get_mirror_tree(root -> left);
    get_mirror_tree(root -> right);
    struct Node * tmp = root -> left;
    root -> left = root -> right;
    root -> right = tmp;
}


bool is_identical(struct Node* r1, struct Node* r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;

    if (r1 == NULL && r2 == NULL)
        return false;

    if (r1 -> data == r2 -> data)
        return is_identical(r1 -> left, r2 -> left) && is_identical(r1 -> right, r2 -> right);
    else
        return false;
}

// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root)
{
    /*std::vector<int> preorder, inorder;
    get_inorder(root, inorder);
    get_preorder(root, preorder);

    for (int i = 0; i < inorder.size(); ++i)
    {
        cout << inorder[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < inorder.size(); ++i)
    {
        cout << preorder[i] << " ";
    }
    cout << endl;
    */
    get_mirror_tree(root -> right);

    return is_identical(root->left, root->right);
}