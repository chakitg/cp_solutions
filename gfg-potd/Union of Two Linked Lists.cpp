// Given two linked lists, your task is to complete the function makeUnion(), that returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

// Example 1:

// Input:
// L1 = 9->6->4->2->3->8
// L2 = 1->2->8->6->2
// Output: 
// 1 2 3 4 6 8 9
// Explaination: 
// All the distinct numbers from two lists, when sorted forms the list in the output. 
// Example 2:

// Input:
// L1 = 1->5->1->2->2->5
// L2 = 4->5->6->7->1
// Output: 
// 1 2 4 5 6 7
// Explaination: 
// All the distinct numbers from two lists, when sorted forms the list in the output.
// Your Task:
// The task is to complete the function makeUnion() which makes the union of the given two lists and returns the head of the new list.

// Expected Time Complexity: O((N+M)*Log(N+M))
// Expected Auxiliary Space: O(N+M)

// Constraints:
// 1<=N,M<=104


// structure of the node is as follows

/* struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        set<int> st;

    Node *current1 = head1;
    Node *current2 = head2;

    while (current1 != nullptr)
    {
        st.insert(current1->data);
        current1 = current1->next;
    }
    while (current2 != nullptr)
    {
        st.insert(current2->data);
        current2 = current2->next;
    }

    Node *dummy = new Node(-1);  // Dummy node to simplify linked list construction
    Node *current = dummy;

    for (int val : st)
    {
        current->next = new Node(val);
        current = current->next;
    }

    return dummy->next;
    }
};
