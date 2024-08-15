You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
Input: LinkedList: 1->2->3
Output: 124
 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= len(list) <= 105
0 <= list[i] <= 9






class Solution {
public:
    // Helper function to reverse a linked list
    Node* reverse(Node *root) {
        Node *prev = NULL;  // Initialize the previous pointer
        Node *curr = root;  // Start with the current node as the head
        Node *next = NULL;  // Next pointer to store the next node temporarily

        // Traverse the list, reversing the links between nodes
        while (curr) {
            next = curr->next;  // Store the next node
            curr->next = prev;   // Reverse the current node's next pointer
            prev = curr;         // Move the previous pointer forward
            curr = next;         // Move the current pointer forward
        }

        // Return the new head (previously the tail)
        return prev;
    }

    Node* addOne(Node* head) {
        // Reverse the linked list to start addition from the least significant digit
        head = reverse(head);
        Node *temp = head;  // Pointer to traverse the reversed list

        int carry = 1;  // Initialize carry as 1 because we are adding one
        while (temp) {
            int val = temp->data + carry;  // Add carry to the current node's data
            temp->data = val % 10;  // Update the node's data to the remainder (current digit)
            carry = val / 10;  // Update carry (will be 0 or 1)
            if (!carry) break;  // If there's no carry left, stop

            temp = temp->next;  // Move to the next node
        }

        // Reverse the list back to its original order
        head = reverse(head);

        // If there's still a carry, we need to add a new node at the beginning
        if (carry) {
            Node *newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }

        // Return the modified head of the list
        return head;
    }
};
