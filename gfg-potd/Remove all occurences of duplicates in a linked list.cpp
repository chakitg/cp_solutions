Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list. 

Examples:

Input: Linked List = 23->28->28->35->49->49->53->53
Output: 23 35
Explanation: 

The duplicate numbers are 28, 49 and 53 which are removed from the list.
Input: Linked List = 11->11->11->11->75->75
Output: Empty list
Explanation: 

All the nodes in the linked list have duplicates. Hence the resultant list would be empty.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ size(list) ≤ 105




class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        Node * temp = head;
        temp = new Node(-1);
        Node * newHead = temp;
        temp->next = head;
        while(temp->next){
            Node* pointer = temp->next->next;
            bool f=false;
            while(pointer && temp->next->data == pointer->data){
                pointer=pointer->next;
                f=true;
            }
            if(f){
                temp->next = pointer;
            }else{
                temp = temp->next;
            }
        }
        return newHead->next;
    }
};
