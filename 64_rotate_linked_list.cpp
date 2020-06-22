// https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node * next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

void insert_end(struct Node*head_ref, int new_data)
{
	struct Node *node = head_ref;
	struct Node *new_node = new Node(new_data);
	while (node->next)
		node = node->next;
	node -> next = new_node;
}


struct Node* insert_start(struct Node *head_ref, int new_data)
{
	struct Node *node = head_ref, *new_node = new Node(new_data);

	// if list is empty
	if (!head_ref)
		return new_node;

	// if list is not empty
	new_node -> next = head_ref;
	return new_node;
}


int get_middle(struct Node* head_ref)
{
	struct Node *slow_ptr = head_ref, *fast_ptr = head_ref;
	while (fast_ptr && fast_ptr->next)
	{
		slow_ptr = slow_ptr -> next;
		fast_ptr = fast_ptr -> next -> next;
	}
	return slow_ptr->data;
}


struct Node* reverse_list(struct Node* head_ref)
{
	struct Node *prev = NULL, *cur = head_ref, *temp;
	if (!head_ref)
	{
		return NULL;
	}
	else if (!head_ref -> next)
	{
		return head_ref;
	}

	while (cur)
	{
		temp = cur -> next;
		cur -> next = prev;
		prev = cur;
		cur = temp;
	}
	return prev;
}

struct Node* delete_all(struct Node * head_ref)
{
	head_ref = NULL;
	return head_ref;
}



void print_list(struct Node *head_ref)
{
	struct Node *node = head_ref;
	if (!node)
	{
		cout << "empty list" << endl;
		return;
	}
	while (node)
	{
		cout << node->data << " ";
		node = node -> next;
	}
	cout << endl;
}


struct Node * rotate(struct Node* head, int k)
{
	struct Node* node = head, *tmp, *head_ref = head;
	while (--k && node)
	{
		node = node -> next;
	}
	// cout << k << endl;

	if (node && node -> next)
	{
		head = node->next;
		node -> next = NULL;


		node = head;
		while (node-> next)
			node = node -> next;
		node -> next = head_ref;

	}
	return head;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n, data, new_data, rotations;
		cin >> n;
		cin >> data;
		struct Node* head = new Node(data);

		for (int i = 1; i < n; ++i)
		{
			cin >> new_data;
			// cout << "inserting " << new_data << endl;
			insert_end(head , new_data);
		}
		cin >> rotations;
		head = rotate(head, rotations);
		print_list(head);
	}
	return 0;
}
