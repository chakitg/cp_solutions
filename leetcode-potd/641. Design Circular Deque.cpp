Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.


class MyCircularDeque {
    vector<int> d; int f, r, sz, cap;
public:
    MyCircularDeque(int k) : d(k), f(0), r(0), sz(0), cap(k) {}
    inline bool insertFront(int v) { if (isFull()) return false; f = (f - 1 + cap) % cap; d[f] = v; sz++; return true; }
    inline bool insertLast(int v) { if (isFull()) return false; d[r] = v; r = (r + 1) % cap; sz++; return true; }
    inline bool deleteFront() { if (isEmpty()) return false; f = (f + 1) % cap; sz--; return true; }
    inline bool deleteLast() { if (isEmpty()) return false; r = (r - 1 + cap) % cap; sz--; return true; }
    inline int getFront() { return isEmpty() ? -1 : d[f]; }
    inline int getRear() { return isEmpty() ? -1 : d[(r - 1 + cap) % cap]; }
    inline bool isEmpty() { return !sz; }
    inline bool isFull() { return sz == cap; }
};
