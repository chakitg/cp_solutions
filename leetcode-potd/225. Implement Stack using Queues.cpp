Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.



class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        // Constructor, no initialization needed for queues
    }
    
    void push(int x) {
        // Push the new element onto q1
        q1.push(x);
    }
    
    int pop() {
        int n = q1.size();
        
        // Transfer the first n-1 elements from q1 to q2
        // This step leaves the last element in q1, which needs to be popped
        for (int i = 0; i < n - 1; i++) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // The last element in q1 is the one to be popped
        int x = q1.front();
        q1.pop();
        
        // Swap the names of q1 and q2 to maintain order
        swap(q1, q2);
        
        return x;
    }
    
    int top() {
        // Return the last element in q1
        return q1.back();
    }
    
    bool empty() {
        // Check if q1 is empty to determine if the stack is empty
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
