Given elements as nodes of the two singly linked lists. The task is to multiply these two linked lists, say L1 and L2.

Note: The output could be large take modulo 109+7.

Examples :

Input: LinkedList L1 : 3->2 , LinkedList L2 : 2
Output: 64
Explanation: 

Multiplication of 32 and 2 gives 64.
Input: LinkedList L1: 1->0->0 , LinkedList L2 : 1->0
Output: 1000
Explanation: 

Multiplication of 100 and 10 gives 1000.
Expected Time Complexity: O(max(n,m))
Expected Auxilliary Space: O(1)
where n is the size of L1 and m is the size of L2

Constraints:
1 <= number of nodes <= 9
0 <= node->data <= 9



class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // Aman Yadav
        long long number1 = 0, number2 = 0;
        int modulus = 1000000007;
        Node *currentNode = first;
        
        while(currentNode) {
            number1 = (number1 * 10 + (currentNode->data)) % modulus;
            currentNode = currentNode->next;
        }
        
        currentNode = second;
        while(currentNode) {
            number2 = (number2 * 10 + (currentNode->data)) % modulus;
            currentNode = currentNode->next;
        }
        
        return (number1 * number2) % modulus;
    }
};
