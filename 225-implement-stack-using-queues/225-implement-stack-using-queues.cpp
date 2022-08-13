class MyStack {
public:
    
   /*
   Using 2 Queues
   */
    
    queue<int> q1;
   
    
    MyStack() {
        
    }
    
    void push(int x) {
        
       q1.push(x);
       int n = q1.size();
       n = n-1;
        
        while(n--){
            q1.push(q1.front());
            q1.pop();
        }
        
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
       return q1.front();
    }
    
    bool empty() {
        
        if(q1.empty())
            return true ;
        else
            return false ;
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