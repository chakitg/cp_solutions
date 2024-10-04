Given a Circular Linked List. The task is to delete the given node, key in the circular linked list, and reverse the circular linked list.

Note:

You don't have to print anything, just return the head of the modified list in each function.
Nodes may consist of Duplicate values.
The key may or may not be present.
Examples:

Input: Linked List: 2->5->7->8->10, key = 8

Output: 10->7->5->2 
Explanation: After deleting 8 from the given circular linked list, it has elements as 2, 5, 7, 10. Now, reversing this list will result in 10, 7, 5, 2 & the resultant list is also circular.
Input: Linked List: 1->7->8->10, key = 8

Output: 10->7->1
Explanation: After deleting 8 from the given circular linked list, it has elements as 1, 7,10. Now, reversing this list will result in 10, 7, 1 & the resultant list is also circular.
Input: Linked List: 3->6->4->10, key = 9
Output: 10->4->6->3
Explanation: As there no key present in the list, so simply reverse the list & the resultant list is also circular.
Expected Time Complexity: O(n)
Expected Auxillary Space: O(1)

Constraints:
2 <= number of nodes, key  <= 105
1 <= node -> data <= 105



class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
        if(head==NULL||head->next==head){
            return head;
        }
        Node* prev=NULL;
        Node* curr=head;
        Node* next;
        do{
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }while(curr!=head);
        head->next=prev;
        head=prev;
        return head;
    }
    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // code here
         if(head==NULL){
            return NULL;
        }
        if(head->data==key){
            if(head->next==head){
                delete head;
                return NULL;
            }
            Node* last=head;
            while(last->next!=head){
                last=last->next;
            }
            last->next=head->next;
            Node* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        Node* prev;
        Node* curr=head;
        while(curr->next!=head){
            if(curr->data==key){
                prev->next=curr->next;
                delete curr;
                return head;
            }
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};
