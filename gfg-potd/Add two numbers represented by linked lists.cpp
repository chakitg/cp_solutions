Given two numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Example 1:

Input:
n = 2
num1 = 45 (4->5->null)
m = 3
num2 = 345 (3->4->5->null)
Output: 
3->9->0->null  
Explanation: 
For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Example 2:

Input:
n = 4
num1 = 0063 (0->0->6->3->null)
m = 2
num2 = 07 (0->7->null)
Output: 
7->0->null
Explanation: 
For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(max(n,m)) for the resultant list.

Constraints:
1 <= n, m <= 104





class Solution
{
    public:
        Node* reverse(Node* head){         Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL;

        while(curr){
            forward = curr->next;
            curr->next = prev;

            prev = curr;
            curr = forward;
        }

        return prev;
    }

    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        Node* rnum1 = reverse(num1);
        Node* rnum2 = reverse(num2);

        Node* ans = new Node(-1);
        Node* temp1 = rnum1;
        Node* temp2 = rnum2;
        Node* anstemp = ans;
        int sum = 0;
        int carry = 0;

        while(temp1 || temp2 || carry){
            sum = 0;
            if(temp1){
                sum += temp1->data;
                temp1 = temp1->next;
            }
            if(temp2){
                sum += temp2->data;
                temp2 = temp2->next;
            }

            sum += carry;

            carry = sum/10;
            anstemp->next = new Node(sum%10);
            anstemp = anstemp->next;
        }

        ans = reverse(ans->next);

        while(ans->data == 0 && ans->next){
            ans = ans->next;
        }

        return ans;
    }
};
