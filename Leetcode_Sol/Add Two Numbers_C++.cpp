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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * res = new ListNode(-1); //res=result to represent another list for result.
ListNode * curr=res; //curr=current to loop over the result list.
int carry=0;
while(l1 || l2)
{
int n1=l1 ? l1->val : 0; //n1=pointing to l1 to check null or not.
int n2=l2 ? l2->val : 0; //n2=pointing to l2 to check null or not.
int sum=n1 + n2 + carry;
carry=sum/10;
curr->next = new ListNode(sum%10);
curr=curr->next;

     if(l1)
         l1=l1->next;
     
     if(l2)
         l2=l2->next;
 }
 if(carry)
     curr->next= new ListNode(1);   //if carry>0 then put carry at new created last node.
 
 return res->next;
    }
};