class MinStack {
private:
    /*
    The trick behind this design challenge is to store an addition O(n) prefix stack consisting of minimums.
    This allows you to store the minimum and maintain it whenever you push or pop values in O(1) time.
    */
    stack<int> valStack;
    stack<int> minStack;
public:
    MinStack() {}
    
    void push(int val) {
        valStack.push(val);
        if(minStack.empty()) {
            minStack.push(val);
        } else {
            /* 
               You want to have the same number of elements in valStack and minStack, except
               minStack stores the minimum of all values. So following this invariants, you
               only have to compare the current value against the top of the stack in O(1) time.
            */
            minStack.push(min(val, minStack.top()));
        }
    }
        
    void pop() {
        // Maintain the invariants of the same amount of values in both stacks.
        valStack.pop();
        minStack.pop();
    }
        
    int top() {
        // Trivial.
        return valStack.top();
    }
        
    int getMin() {
        // By keeping a minStack, we know the minimum value is the top: O(1) time!
        return minStack.top();
    }
};
    
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */