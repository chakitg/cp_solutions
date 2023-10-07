Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n



class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0); // Create a dummy node.
        dummy->next = head;
        ListNode *prev = dummy; //the prev pointer on the dummy node.

        for (int i = 0; i < left - 1; i++) {
            prev = prev->next; // Move the prev pointer to the (left - 1)-th node.
        }

        ListNode *current = prev->next; // The current pointer starts just after the prev.

        // Reverse the portion.
        for (int i = 0; i < right - left; i++) {
            ListNode *x = current->next; // save current->next 
            current->next = x->next; // Update current's next 
            x->next = prev->next; // Insert x node between prev and its next node.
            prev->next = x; // Update prev's next to point to forw.
        }

        return dummy->next; 
    }
};
