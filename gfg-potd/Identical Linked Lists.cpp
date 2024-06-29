Given the two singly Linked Lists respectively. The task is to check whether two linked lists are identical or not. 
Two Linked Lists are identical when they have the same data and with the same arrangement too. If both Linked Lists are identical then return true otherwise return false. 

Examples:

Input:
LinkedList1: 1->2->3->4->5->6
LinkedList2: 99->59->42->20
Output: false
Explanation:

As shown in figure linkedlists are not identical.
Input:
LinkedList1: 1->2->3->4->5
LinkedList2: 1->2->3->4->5
Output: true
Explanation: 
 
As shown in figure both are identical.
Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)

Constraints:
1 <= length of lists <= 103








bool areIdentical(struct Node *head1, struct Node *head2) {
    // Code here
    while(true){
        if(head1==nullptr && head2==nullptr){
            return true;
        }
        if(head1==nullptr || head2==nullptr){
            return false;
        }
        if(head1->data!=head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}
