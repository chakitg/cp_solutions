You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.

Example 1:

Input:
L1 = 1->0->0
L2 = 1->2
Output: 88
Explanation:  
First linked list represents 100 and the
second one represents 12. 12 subtracted from 100
gives us 88 as the result. It is represented
as 8->8 in the linked list.
Example 2:

Input:
L1 = 0->0->6->3
L2 = 7->1->0
Output: 647
Explanation: 
First linked list represents 0063 => 63 and 
the second one represents 710. 63 subtracted 
from 710 gives us 647 as the result. It is
represented as 6->4->7 in the linked list.
Your Task:
You do not have to take any input or print anything. The task is to complete the function subLinkedList() that takes heads of two linked lists as input parameters and which should subtract the smaller number from the larger one represented by the given linked lists and return the head of the linked list representing the result.

n and m are the length of the two linked lists respectively.
Expected Time Complexity:  O(n+m)
Expected Auxiliary Space: O(n+m)

Constraints:
1 <= n <= 10000
0 <= values represented by the linked lists < 10n
0 <= values represented by the linked lists < 10m






class Solution {
public:
    Node * reverse(Node * head) {
        Node * prev = nullptr, * cur = head;
        
        while(cur){
            Node * next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
    
    pair<Node *, Node *> subtract(Node * head1, Node * head2) {
        LinkedList ans, second;
        int carry = 0;
        
        while(head1 or head2){
            int cur = (head1 ? head1 -> data : 0) - (head2 ? head2 -> data : 0) - carry;
            carry = cur < 0;
            
            if(carry){
                if((head1 and head1 -> next) or (head2 and head2 -> next)){
                    ans.insert(10 + cur);
                    second.insert(0);
                }
                else{
                    second.insert(abs(cur));
                }
            }
            else{
                ans.insert(cur);
                second.insert(0);
            }
            
            if(head1)
                head1 = head1 -> next;
            if(head2)
                head2 = head2 -> next;
        }
        
        
        if(carry){
            return {second.head, ans.head};
        }
        else{
            return {ans.head, nullptr}; // nullptr indicate that F >= S
        }  
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        pair<Node *, Node *> res = subtract(head1, head2);
        Node * final_ans;
        
        if(res.second){
            head1 = res.first;
            head2 = res.second;
            
            final_ans = subtract(head1, head2).first;
        }
        else{
            final_ans = res.first;
        }
        
        final_ans = reverse(final_ans);
        
        while(final_ans -> data == 0 and final_ans -> next)
            final_ans = final_ans -> next;
        
        return final_ans;
    }
};
