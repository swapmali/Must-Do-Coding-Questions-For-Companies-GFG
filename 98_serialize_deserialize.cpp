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
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str;)
		ip.push_back(str);

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
		if (i >= ip.size())
			break;
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

// my code

void serialize(Node *root, vector<int> &a)
{
	queue <Node*> q;
	Node* node;
	if (root != NULL)
	{
		a.push_back(root -> data);
		q.push(root);
	}

	while (!q.empty())
	{
		node = q.front();
		q.pop();

		if (node -> left != NULL)
		{
			a.push_back(node -> left -> data);
			q.push(node -> left);
		}
		else
		{
			a.push_back(0);
		}

		if (node -> right != NULL)
		{
			a.push_back(node -> right -> data);
			q.push(node -> right);
		}
		else
		{
			a.push_back(0);
		}
	}

	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &a)
{
	if (a.size() == 0)
		return NULL;

	Node * root, *node, *l, *r;
	queue <Node *>q, cur_parent, next_parent;

	for (int i = 0; i < a.size(); ++i)
	{
		node = new Node(a[i]);
		q.push(node);
	}


	// int i = 1;
	int flg = 0, tmp;

	cur_parent.push(q.front());
	q.pop();

	while (!q.empty())
	{
		while (!cur_parent.empty())
		{
			node = cur_parent.front();

			if (!flg)
			{
				root = node;
				flg = 1;
			}

			cur_parent.pop();

			l = q.front();
			q.pop();
			r = q.front();
			q.pop();

			if (l -> data != 0)
			{
				node -> left = l;
				next_parent.push(l);
			}

			if (r -> data != 0)
			{
				node -> right = r;
				next_parent.push(r);
			}
		}

		while (!next_parent.empty())
		{
			node = next_parent.front();
			next_parent.pop();

			cur_parent.push(node);
		}
	}
	return root;
}

void inorder(Node *root) {
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main() {
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
		vector<int> A;
		serialize(root, A);

		Node *getRoot = deSerialize(A);
		inorder(getRoot);
		cout << "\n";

	}
	return 0;
}