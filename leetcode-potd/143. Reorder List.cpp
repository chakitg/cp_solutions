You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000





class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode*prev=NULL,*next=head;
        while(head){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }

    ListNode* merge(ListNode* h1,ListNode* h2){
        if(h1==NULL)return h2;
        if(h2->next==NULL)return h1;
        h1->next=merge(h2,h1->next);
        return h1;
    }

    ListNode* findmid(ListNode* head){
        ListNode* slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)return;

        ListNode* mid=findmid(head);
        ListNode* head_of_revll=reverse(mid);
        merge(head,head_of_revll);
    }
};
