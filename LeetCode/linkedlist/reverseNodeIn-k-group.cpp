/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;
        ListNode *tmp = nullptr;
        int count = 1, listLen = 0;
        ListNode *start = current;

    while(current != nullptr)
    {
        current = current->next;
        listLen++;
    }

    current = head;
    while(current != nullptr && listLen >= k)
    {
        start = current;
        if (listLen >= k) {
        while(current != nullptr && count <= k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
            listLen--;
        }
        }
        // cout << "start = " << start->val << " and prev = " << prev->val;
        // if (tmp != nullptr)
        //     cout << " tmp = " << tmp->val << endl;
        // else
        //     cout << endl;
        count = 1;

        if (start == head) {
            //cout << "start is head" << endl;
            head = prev;
        }
        else if (start != head)
        {
            tmp->next = prev;
        }
        start->next = current;
        tmp = start;
    
    }

        return head;
    }

};
