// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};

void leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

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

	// for(string i:ip)
	//     cout<<i<<" ";
	// cout<<endl;
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
		leftView(root);
		cout << endl;
	}
	return 0;
}


int get_height(struct Node* root)
{
	if (root == NULL)
		return 0;

	return 1 + max(get_height(root -> left), get_height(root -> right));
}

void get_left_view(struct Node* root, std::vector<int> &lv, int level)
{
	if (root == NULL)
		return;
	// cout << "for:" << root->data << " level:" << level << endl;
	if (!lv[level])
		lv[level] = root -> data;

	get_left_view(root -> left, lv, level + 1);
	get_left_view(root -> right, lv, level + 1);
}


void leftView(struct Node *root)
{
	int h = get_height(root);
	std::vector<int> lv(h, 0);

	get_left_view(root, lv, 0);

	for (int i = 0; i < lv.size(); ++i)
		cout << lv[i] << " ";
	cout << endl;
}
