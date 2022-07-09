class Solution {
public:
    
    // simple bfs traversal 
    
  
    bool canReach(vector<int>& A, int cur) {
        
       queue<int> q;
        q.push(cur);
        while(size(q)) {
            cur = q.front();
            q.pop();
            
            // target reached
            if(A[cur] == 0)
                return true;  
            
              // already visited - stop further exploration of this path
            if(A[cur] < 0) 
                continue;  
            
              // try forward jump
            if(cur + A[cur] < size(A))
                q.push(cur + A[cur]);  
             // try backward jump
            if(cur - A[cur] >= 0)    
                q.push(cur - A[cur]); 
            
             // mark current index as visited by negating
            A[cur] *= -1;                                      
        }
        
         // explored all array without reaching target
        return false;            
    }
};