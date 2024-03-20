You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


Build the result list and return its head.

 

Example 1:


Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
Example 2:


Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.
 

Constraints:

3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104





class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode();
        dummy->next = list1;
        
        ListNode* prevA = dummy;
        for (int i = 0; i < a; ++i) {
            prevA = prevA->next;
        }
        
        ListNode* prevB = prevA;
        for (int i = a; i <= b + 1; ++i) {
            prevB = prevB->next;
        }
        
        ListNode* list2Tail = list2;
        while (list2Tail->next != nullptr) {
            list2Tail = list2Tail->next;
        }
        
        prevA->next = list2;
        list2Tail->next = prevB;
        
        return dummy->next;
    }
};
