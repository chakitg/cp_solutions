class Solution {
public:
    // Function to return a list of integers denoting the node 
    // values of both the BST in a sorted order.
    vector<int> merge(Node* root1, Node* root2) {
        Node* head1 = nullptr;
        Node* head2 = nullptr;

        convertIntoSortedDLL(root1, &head1);
        convertIntoSortedDLL(root2, &head2);

        Node* res = mergeLinkedList(head1, head2);

        vector<int> result;
        while (res != nullptr) {
            result.push_back(res->data);
            res = res->right;
        }

        return result;
    }

    // Helper function to convert BST to sorted doubly linked list
    void convertIntoSortedDLL(Node* root, Node** head) {
        if (root == nullptr) {
            return;
        }

        convertIntoSortedDLL(root->right, head);
        root->right = *head;

        if (*head != nullptr) {
            (*head)->left = root;
        }

        *head = root;

        convertIntoSortedDLL(root->left, head);
    }

    // Helper function to merge two sorted doubly linked lists
    Node* mergeLinkedList(Node* head1, Node* head2) {
        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (true) {
            if (head1 == nullptr) {
                tail->right = head2;
                break;
            }

            if (head2 == nullptr) {
                tail->right = head1;
                break;
            }

            if (head1->data <= head2->data) {
                tail->right = head1;
                head1->left = tail;
                head1 = head1->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                head2 = head2->right;
            }

            tail = tail->right;
        }

        Node* res = dummy->right;
        if (res != nullptr) {
            res->left = nullptr;
        }

        delete dummy;
        return res;
    }
};
