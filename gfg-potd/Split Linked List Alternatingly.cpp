Given a singly linked list's head. Your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller lists. The sublists should be made from alternating elements from the original list.
Note: 

The sublist should be in the order with respect to the original list.
Your have to return an array containing the both sub-linked lists.
Examples:

Input: LinkedList = 0->1->0->1->0->1
Output: 0->0->0 , 1->1->1
Explanation: After forming two sublists of the given list as required, we have two lists as: 0->0->0 and 1->1->1.

Input: LinkedList = 2->5->8->9->6
Output: 2->8->6 , 5->9
Explanation: After forming two sublists of the given list as required, we have two lists as: 2->8->6 and 5->9.
Input: LinkedList: 7 
Output: 7 , <empty linked list>
Constraints:
1 <= number of nodes <= 100
1 <= node -> data <= 104



class Solution {
  public:
    // Function to append a new node with newData at the end of a linked list
    void append(struct Node** headRef, int newData) {
        struct Node* new_node = new Node(newData);
        struct Node* last = *headRef;
        if (*headRef == NULL) {
            *headRef = new_node;
            return;
        }
        while (last->next != NULL)
            last = last->next;
        last->next = new_node;
    }
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        struct Node* a = NULL;
        struct Node* b = NULL;
        struct Node* current = head; // Initialize current as head
        // Iterate through the list
        while (current != NULL) {
            append(&a, current->data); // Append current node's data to list a
            current = current->next;   // Move current to the next node
            // If current is not NULL, append its data to list b and move current to the
            // next node
            if (current != NULL) {
                append(&b, current->data);
                current = current->next;
            }
        }
        return {a, b};
    }
};
