// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
  int data;
  Node* next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  cout << endl;
}

// Driver program to test above functions
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;
    struct Node *arr[N];
    for (int j = 0; j < N; j++)
    {
      int n;
      cin >> n;

      int x;
      cin >> x;
      arr[j] = new Node(x);
      Node *curr = arr[j];
      n--;

      for (int i = 0; i < n; i++)
      {
        cin >> x;
        Node *temp = new Node(x);
        curr->next = temp;
        curr = temp;
      }
    }

    Node *res = mergeKLists(arr, N);
    printList(res);
  }
  return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
  int data;
  Node* next;

  Node(int x){
      data = x;
      next = NULL;
  }

};
*/

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */


void minheapify_up(vector<Node*> &minheap, int size, int i)
{
  if (i < 0)
    return;

  int left = 2 * i + 1;
  int right = left + 1;
  int smallest = i;

  if (left < size && (minheap[left]->data) < (minheap[smallest]->data))
    smallest = left;
  if (right < size && (minheap[right]->data) < (minheap[smallest]->data))
    smallest = right;

  if (smallest != i)
  {
    swap(minheap[i], minheap[smallest]);
  }
  minheapify_up(minheap, size, (i + 1) / 2 - 1);
}

void minheapify_down(vector<Node*> &minheap, int size, int i)
{
  int left = 2 * i + 1;
  int right = left + 1;
  int smallest = i;

  if (left < size && (minheap[left]->data) < (minheap[smallest]->data))
    smallest = left;
  if (right < size && (minheap[right]->data) < (minheap[smallest]->data))
    smallest = right;

  if (smallest != i)
  {
    swap(minheap[i], minheap[smallest]);
    minheapify_down(minheap, size, smallest);
  }
}


Node * mergeKLists(Node *arr[], int N)
{
  int size = 0;
  // create a minheap of size of no of linked list to be merged
  // i.e. at a time one ele from each list will be present in minheap
  vector<Node*> minheap(N);

  for (int i = 0; i < N; i++)
  {
    minheap[i] = arr[i];
    size++;
    minheapify_up(minheap, size, i);
  }

  Node* node, *head, *prev, *next_node;
  int flg = 0;
  while (size > 0)
  {
    node = minheap[0];

    // if head is not selected
    if (!flg)
    {
      head = node;
      prev = head;
      flg = 1;
    }
    else
    {
      prev->next = node;
      prev = node;
    }

    next_node = node->next;

    // if next_node from the extracted min linked list exists add it to minheap
    if (next_node != NULL)
    {
      minheap[0] = next_node;
    }
    else // means no current list is empty decrease the minheap size
    {
      minheap[0] = minheap[size - 1];
      size--;
    }
    minheapify_down(minheap, size, 0);
  }
  return head;
}

















