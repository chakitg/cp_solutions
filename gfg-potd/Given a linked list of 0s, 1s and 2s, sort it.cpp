Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.
Example 2:

Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.
Your Task:
The task is to complete the function segregate() which segregates the nodes in the linked list as asked in the problem statement and returns the head of the modified linked list. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 106



  
class Solution
{
    public:

    Node* segregate(Node *head) {
        Node* temp = head;
        int count_0 = 0;
        int count_1 = 0;
        int count_2 = 0;

        while(temp != NULL) {
            if(temp->data == 0) count_0++;
            else if(temp->data == 1) count_1++;
            else count_2++;
            
            temp = temp->next;
        }

        temp = head;

        while(count_0--) {
            temp->data = 0; 
            temp = temp->next;
        }
        while(count_1--) {
            temp->data = 1;
            temp = temp->next;
        }
        while(count_2--) {
            temp->data = 2;
            temp = temp->next;
        }
        
        return head;
        
    }
};
