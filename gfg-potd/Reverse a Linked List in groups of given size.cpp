Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which should reverse the linked list in group of size k and return the head of the modified linked list.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 105
1 <= k <= N



class Solution
{
    public:
    int lengthOfLL(node *head) {
        int l = 0;
        node *p = head;
        
        while(p) {
            l++;
            p = p->next;
        }
        
        return l;
    }
    
    struct node *reverse (struct node *head, int k)
    {
        if(!head)
            return NULL;
            
        if(!head->next)
            return head;
            
        int len = lengthOfLL(head);
        node *temp = new node(0);
        node *curr, *nxt, *prev = temp;
        temp->next = head;
        
        while(k <= len) {
            curr = prev->next;
            nxt = curr->next;
            
            for(int i = 0; i < k - 1; i++) {
                curr->next = nxt->next;
                nxt->next = prev->next;
                
                prev->next = nxt;
                nxt = curr->next;
            }
            
            prev = curr;
            len -= k;
        }
        
        if(len <= k) {
            node *t = curr, *p = NULL;
            curr = curr->next;
            
            while(nxt) {
                nxt = curr->next;
                curr->next = p;
                
                p = curr;
                curr = nxt;
            }
            
            t->next = p;
        }
        
        return temp->next;
    }
};
