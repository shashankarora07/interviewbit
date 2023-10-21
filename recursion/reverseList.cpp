#include<bits/stdc++.h>

using namespace std;

typedef struct linkedList
{
	int data;
	struct linkedList *next;
}Node;

Node *reverseListRecursion(Node* head, Node **saveHead)
{
	if (head == NULL) {
		cerr << "head Null";
		return NULL;
	}
	if (head->next == NULL) {
		cout << " base condition met: " << head->data << " <---" << endl;
		*saveHead = head;
		return head;
	}

	Node *start = reverseListRecursion(head->next, saveHead);
	start->next = head;
	head->next = NULL;

	return head;
}

Node *reverseList(Node *head)
{
	if (head == NULL) {
		cerr << "List empty";
		return NULL;
	}

	Node *start = head;
	Node *savehead = NULL;
	start = reverseListRecursion(start, &savehead );

	return savehead;
}


Node *newNode(Node* head, int val)
{
	Node* newnode = (Node *)malloc(sizeof(Node));
	newnode->next = NULL;
	newnode->data = val;

	if (!newnode) {
		cerr << "malloc failed";
		return NULL;
	}

	return newnode;
}

void printList(Node *node)
{
	cout << __func__ << " starts: " << endl;
	while (node != NULL) {
		cout << node->data << " --> ";
		node = node->next;
	}
	cout << "NULL" << endl;
}

int main()
{
	Node *start = NULL;

	start = newNode(start,1);
	Node *head = start;

	for (int i = 2; i <=5; i++) 
	{
		Node * newnode = newNode(head,i);
		head->next = newnode;
		head = newnode;
	}

	printList(start);

	Node *reverseStart = reverseList(start);
	printList(reverseStart);

	return 0;
}
