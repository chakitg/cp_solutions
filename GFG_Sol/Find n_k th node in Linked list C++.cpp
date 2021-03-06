// Given a singly linked list and a number k. Write a function to find the (N/k)th element, where N is the number of elements in the list. We need to consider ceil value in case of decimals.

// Input:
// The first line of input contains an integer T denoting the number of test cases. The first line of each test case consists of an integer N. The second line consists of N spaced integers.The last line consists of an integer k.

// Output:
// Print the data value of (N/k)th node in the Linked List.

// User Task:
// The task is to complete the function fractional_node() which should find the n/kth node in the linked list and return its data value.

// Constraints: 
// 1 <= T <= 100
// 1 <= N <= 100

// Example:
// Input:
// 2
// 6
// 1 2 3 4 5 6
// 2
// 5
// 2 7 9 3 5
// 3

// Output:
// 3
// 7

// Explanation:
// Testcase 1: 6/2th element is the 3rd(1-based indexing) element which is 3.

//-------------------------------------------------------------------------------------------------------------


#include<bits/stdc++.h>
using namespace std;

int fractional_node(struct Node* head,int k);

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* ptr,*start = NULL,*ptr1;
        int n,i;
        cin>>n;
        
        for(i=0;i<n;i++)
        {
            int value;
            cin>>value;
            
            ptr=new Node(value);
            
            if(start==NULL)
            {
                start=ptr;
                ptr1=ptr;
            }
            else
            {
                ptr1->next=ptr;
                ptr1=ptr1->next;
            }
        }
        ptr1->next=NULL;
        int k;
        cin>>k;
        int p = fractional_node(start,k);
        cout<<p<<endl;
    }
}
// } Driver Code Ends


/*The structure of the node is
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
int fractional_node(struct Node *head, int k)
{
    // your code here
    auto slow=head,fast=head;
    while(fast){
        for(int i=0;fast&&i<k;i++)fast=fast->next;
        if(fast)slow=slow->next;
    }
    return slow->data;
    
}
