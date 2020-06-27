// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
	Node(int new_data)
	{
		data = new_data;
		left = right = NULL;
	}
};


void print_inorder(struct Node *root)
{
	if (root == NULL)
		return;

	print_inorder(root -> left);
	cout << root -> data << " ";
	print_inorder(root -> right);
}

void print_preorder(struct Node *root)
{
	if (root == NULL)
		return;

	cout << root -> data << " ";
	print_preorder(root -> left);
	print_preorder(root -> right);
}

void print_postorder(struct Node *root)
{
	if (root == NULL)
		return;

	print_postorder(root -> left);
	print_postorder(root -> right);
	cout << root -> data << " ";
}

int get_size(struct Node *root)
{
	if (root == NULL)
		return 0;

	return 1 + get_size(root -> left) + get_size(root -> right);
}

int get_height(struct Node *root)
{
	if (root == NULL)
		return 0;

	return 1 + max(get_height(root -> left), get_height(root -> right));
}

int main()
{
	/* Constructed binary tree is
	          1
	        /   \
	      2      3
	    /  \
	  4     5
	*/
	struct Node *root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);
	root -> left -> left = new Node(4);
	root -> left -> right = new Node(5);

	cout << "Inorder: ";
	print_inorder(root);
	cout << endl;

	cout << "Preorder: ";
	print_preorder(root);
	cout << endl;

	cout << "Postorder: ";
	print_postorder(root);
	cout << endl;

	cout << "Size of tree: " << get_size(root) << endl;

	cout << "Height of tree: " << get_height(root) << endl;
	return 0;
}
