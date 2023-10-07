class MinStack {
public:
    
    stack<int>st;
    int minInStack = INT_MAX;
   
    void push(int x) {
        if(x <= minInStack){
            st.push(minInStack);
            minInStack = x;
        }
        st.push(x);
    }
    
    void pop() {
       int tmp = st.top();
        st.pop();
        if(tmp == minInStack){
            minInStack = st.top();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minInStack;
    }
};