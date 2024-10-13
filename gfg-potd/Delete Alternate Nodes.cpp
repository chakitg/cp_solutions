Given a Singly Linked List, Delete all alternate nodes of the list ie delete all the nodes present in even positions.

Examples :

Input: LinkedList: 1->2->3->4->5->6
 
Output: 1->3->5

Explanation: Deleting alternate nodes ie 2, 4, 6 results in the linked list with elements 1->3->5.
Input: LinkedList: 99->59->42->20
 
Output: 99->42
 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 103





class Solution {
  public:
    void deleteAlt(struct Node *head) {
        // Code here
        if(head==NULL || head->next==NULL)
        {
            return;
        }
        Node *curr=head->next;
        Node *prev=head;
        int count =2;
        while(curr!=NULL)
        {
            if(count%2==0)
            {
                Node *temp=curr;
                curr=curr->next;
                prev->next=curr;
                delete temp;
            }else{
                prev=curr;
                curr=curr->next;
            }
            count++;
        }
    }
};
