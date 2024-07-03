class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        Node * temp = head;
        temp = new Node(-1);
        Node * newHead = temp;
        temp->next = head;
        while(temp->next){
            Node* pointer = temp->next->next;
            bool f=false;
            while(pointer && temp->next->data == pointer->data){
                pointer=pointer->next;
                f=true;
            }
            if(f){
                temp->next = pointer;
            }else{
                temp = temp->next;
            }
        }
        return newHead->next;
    }
};
