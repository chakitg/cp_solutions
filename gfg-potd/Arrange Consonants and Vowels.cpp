Given a singly linked list having n nodes containing english alphabets ('a'-'z'). Rearrange the linked list in such a way that all the vowels come before the consonants while maintaining the order of their arrival. 

Example 1:

Input:
n = 9
linked list: a -> b -> c -> d -> e -> f -> g -> h -> i 
Output: 
a -> e -> i -> b -> c -> d -> f -> g -> h
Explanation: 
After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.
Example 2:

Input:
n = 8
linked list: a -> b -> a -> b -> d -> e -> e -> d 
Output: 
a -> a -> e -> e -> b -> b -> d -> d
Explanation: 
After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.
Your Task:
Your task is to complete the function arrangeCV(), which takes head of linked list and arranges the list in such a way that all the vowels come before the consonants while maintaining the order of their arrival and returns the head of the updated linked list.

Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(1)

Constraints:
1 <= n <= 104
'a' <= elements of linked list <= 'z'




class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        struct Node* vowel = new Node(0);
        struct Node* cons = new Node(0);
        struct Node* vow = vowel, *con = cons;
        struct Node* curr = head;
        while(curr) {
            char c = curr->data;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vow->next = curr;
                vow = vow->next;
            } else {
                con->next = curr;
                con = con->next;
            }
            curr = curr->next;
        }

        vowel = vowel->next;
        cons = cons->next;
        con->next = NULL;

        if(vowel) {
            vow->next = cons;
            return vowel;
        }

        return cons;

    }
};
