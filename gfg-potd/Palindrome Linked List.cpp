Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.

Examples:

Input: LinkedList: 1->2->1->1->2->1
Output: true
Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

Input: LinkedList: 1->2->3->4
Output: false
Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1) 
Note: You should not use the recursive stack space as well

Constraints:
1 <= number of nodes <= 105
1 ≤ node->data ≤ 103



Node* reverse(Node* node){
        Node* curr = node, *prev = nullptr;
        while(curr){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(Node *head) {
        // Your code here
        Node *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = reverse(slow->next);
        Node* c1 = head, *c2 = slow->next;
        while(c1 && c2){
            if(c1->data!=c2->data){
                return false;
            }
            c1 = c1->next;
            c2 = c2->next;
        }
        return true;
    }
