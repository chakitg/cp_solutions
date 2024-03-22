Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9


  class Solution {
public:
    ListNode* front;
    bool check(ListNode* Node){
        if (Node!=NULL) {
            if (!check(Node->next)) return 0;
        //    cout<<"("<<Node->val<<","<<front->val<<")";
            if (Node->val!=front->val) return 0;
            front=front->next;
        }
        return 1;
    }
    bool isPalindrome(ListNode* head) {
        front=head;
        return check(head);
    }
};
