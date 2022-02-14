class MinStack {
public:
    
    stack<long> s;
    long mini;
    MinStack() {
        mini=LONG_MAX;
    }
    
    // Push : (2 * Val) – (min)
    // Pop : (2 * min) – (modified value) 
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            mini=val;
        }else{
            if(val<mini){
                s.push((long)2*val-mini);
                mini=val;
            }else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        long curr=s.top();
        s.pop();
        if(curr<mini){
            mini=(long)(2*mini-curr);   
        }
    }
    
    int top() {
        long curr=s.top();
        if(curr<mini){
            return mini;
        }else{
            return curr;
        }
    }
    
    int getMin() {
        return mini;
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