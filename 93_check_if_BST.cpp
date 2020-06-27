// https://practice.geeksforgeeks.org/problems/check-for-bst/1
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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



bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);

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

void inorder(Node *root, vector<int> &v)
{
  if (root == NULL)
    return;

  inorder(root->left, v);
  v.push_back(root->data);
  inorder(root->right, v);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  string tc;
  getline(cin, tc);
  t = stoi(tc);
  while (t--)
  {
    string s;
    getline(cin, s);
    Node* root = buildTree(s);
    cout << isBST(root) << endl;
  }
  return 0;
}



// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child
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
void get_inorder(struct Node* root, std::vector<int> &inorder)
{
  if (root == NULL)
    return;

  get_inorder(root -> left, inorder);
  inorder.push_back(root -> data);
  get_inorder(root -> right, inorder);
}

// return true if the given tree is a BST, else return false

bool compare_left_right(Node* root)
{
  if (root == NULL)
    return true;

  if ((root -> left != NULL && (root -> left -> data) >= (root -> data)) || (root->right != NULL && (root -> right -> data) <= (root -> data)))
  {
    return false;
  }

  return compare_left_right(root -> left) && compare_left_right(root -> right);
}


bool isBST(Node* root)
{
  std::vector<int> inorder;
  get_inorder(root, inorder);

  bool sorted = true;
  for (int i = 1; i < inorder.size(); ++i)
  {
    if (inorder[i - 1] >= inorder[i])
    {
      sorted = false;
      break;
    }
  }

  if (sorted && compare_left_right(root))
    return true;
  return false;
}

