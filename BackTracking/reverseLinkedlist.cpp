/* Reverse a linked list using recursion.

Example :

Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL. */


#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

void DisplayList(list<int> L)
{
	for (auto it = L.begin(); it != L.end(); it++)
		cout << *it << " --> ";
	cout << "NULL" << endl;
}

void reverseLinkedlist(list<int> L)
{
	if (L.next != NULL)
		cout << L.val << endl;
}

int main()
{
	list<int> l1 = { 10, 20, 30, 40, 50 };
	list<int> l2(l1.begin(), l1.end());
	DisplayList(l2);
	//l2.reverse();
	//DisplayList(l2);
	reverseLinkedlist(l1);


	return 0;
}


