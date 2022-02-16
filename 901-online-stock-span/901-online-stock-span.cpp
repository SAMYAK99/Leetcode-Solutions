class StockSpanner {
    
     stack<pair<int,int>> s; //1st is index and 2nd is value
         int index;
    
public:
    
    /*
    -> Online Algo  : We can't see future elements. We need to give answer by
       seeing each day Input
    */
    
    StockSpanner() {
        
         index = -1;
    }
    
    int next(int price) {
         index +=1;
        
    //Find the previous greater element && Maintain stack in decreasing order
        while(!s.empty() && s.top().second<=price)   
            s.pop();
        
      //If there is no previous greater element
        if(s.empty()){  
            s.push({index,price});    
            return index+1;   
        }
      
     // Stack is not empty then    
     // Top of the stack will always contains greatest element in stack   
        int result = s.top().first;
        s.push({index,price});
        
        return index-result;  
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */