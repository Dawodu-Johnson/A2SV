class MinStack {
    stack<int>regular_stack, min_stack;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
          
         regular_stack.push(val);
        
         if(min_stack.empty() || min_stack.top() >= val){
              min_stack.push(val);
         }
    }
    
    
    void pop() {
        
          if(min_stack.top()==regular_stack.top())min_stack.pop();
          regular_stack.pop();
    }
    
    int top() {
        
         return regular_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
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
