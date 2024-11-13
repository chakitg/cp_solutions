Given two singly linked lists, return the point where two linked lists intersect.

Note: If the linked lists do not merge at any point, return -1.

Examples:

Input: Linked list 1: 4->4->4->4->4, Linked list 2: 4->4->4
 
Output: 4
Explanation: From the above image, it is clearly seen that the common part is 4->4 whose starting point is 4.

Input: Linked list 1: 4->1->8->4->5, Linked List 2: 5->6->1->8->4->5
 
Output: 8
Explanation: From the above image, it is clearly seen that the common part is 8->4->5 whose starting point is 8.
Input: Linked list 1: 1->2->3, Linked list 2: 4->5->6
Output: -1
Explanation: There is no common part, so there is no interaction point.
Try to solve the problem without using any extra space.

Constraints:
2 ≤ size of first linkedist + size of second linkedlist ≤ 2*105
-10000 ≤ data of nodes ≤ 10000




class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        int len1 = 0, len2 = 0;
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while (temp1 != NULL) {
            len1++;
            temp1 = temp1->next;
        }
        
        while (temp2 != NULL) {
            len2++;
            temp2 = temp2->next;
        }
        
        int diff = abs(len1 - len2);
       
        temp1 = head1;
        temp2 = head2;
        
        if (len1 > len2) {
            for (int i = 0; i < diff; i++) {
                temp1 = temp1->next;
            }
        } else {
            for (int i = 0; i < diff; i++) {
                temp2 = temp2->next;
            }
        }
        
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1 == temp2) {
                return temp1->data;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return -1;
    }
};
