Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int counter = 0;
        while (temp != nullptr) {
            counter++;
            temp = temp->next;
        }

        if (n == counter) {
            ListNode* to_delete = head;
            head = head->next;
            delete to_delete;
            return head;
        }

        ListNode* cur = head;
        int c2 = 0;
        while (c2 != counter - n - 1) {
            c2++;
            cur = cur->next;
        }
        ListNode* to_delete = cur->next;
        cur->next = cur->next->next;
        delete to_delete;
        return head;
    }
};
