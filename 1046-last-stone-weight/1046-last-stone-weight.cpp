class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
          priority_queue<int> maxHeap; 
         
        for(int i : stones)
            maxHeap.push(i);
        
        while(maxHeap.size() > 1){
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();
            
           
            if(a!=b)
                maxHeap.push(max(a,b)-min(a,b));
        }
        
        // cout << maxHeap.size() ; 
        
        if(maxHeap.size() == 0)
            return 0 ; 
        else
        return maxHeap.top() ; 
    }
};