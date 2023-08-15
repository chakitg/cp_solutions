Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200



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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        
        ListNode* smallerHead=new ListNode(); //Head of the list with nodes <x
        ListNode* smallerTail=smallerHead; //Tail of the list with nodes <x
        
        ListNode* greaterHead=new ListNode();//Head of the list with nodes >=x
        ListNode* greaterTail=greaterHead; //Tail of the list with nodes >=x
        
        ListNode* curr = head;
        while (curr) {//partition into greater & smaller lists
            if (curr->val < x) {
                smallerTail->next = curr;
                smallerTail =smallerTail->next;
            } 
            else {
                greaterTail->next = curr;
                greaterTail=greaterTail->next;
            }
            curr = curr->next;
        }
        
        greaterTail->next = NULL; 
        smallerTail->next = greaterHead->next;//Connect the smaller and the greater lists
        
        head = smallerHead->next; //Update the head of the list
       
        return head;
    }
};
