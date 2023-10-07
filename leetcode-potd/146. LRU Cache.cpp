Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.



class LRUCache {
public:
    
    struct node{
        int key;
        int val;
        node* next;
        node* prev;
        node(int k, int v){
            key=k;
            val=v;
            prev=NULL;
            next=NULL;
        }
    };
    
    struct node *head = new node(-1,-1);
    struct node *tail = new node(-1,-1);
    
    int size;
    unordered_map<int,node*> mp; // to store address of node against its key
    
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    // insertion will be done just after head
    void addNode(node *newnode){
        struct node *add_next = head->next;
        
        // linking newnode & 2nd node
        newnode->next = add_next;
        add_next->prev = newnode;
        
        // linking newnode & head
        head->next=newnode;
        newnode->prev=head;
    }
    
    // deletion will be done for node just previous to tail
    void deleteNode(node *node){
        struct node *del_next = node->next;
        struct node *del_prev = node->prev;
        
        del_prev->next = del_next;
        del_next->prev = del_prev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node *resnode=mp[key];
            int res=resnode->val;
            
            // since this node is accessed, it becomes Recently used, deleted from current address & added next to head
            mp.erase(key); 
            deleteNode(resnode);
            addNode(resnode);
            
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // since this node is accessed, it becomes Recently used, deleted from current address & added next to head
        if(mp.find(key)!=mp.end()){
            node *existingnode = mp[key];
            mp.erase(key);
            deleteNode(existingnode);
        }
        
        // if we are adding new node & cache size = capacity, so we need to delete node previous to tail
        if(mp.size()==size){
            node *dnode = tail->prev;
            mp.erase(dnode->key);
            deleteNode(dnode);
        }
        
        addNode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
