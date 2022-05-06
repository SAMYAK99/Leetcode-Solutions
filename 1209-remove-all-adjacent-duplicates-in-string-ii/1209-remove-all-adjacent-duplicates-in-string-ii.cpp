class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n = s.size();
    
         stack<pair<char,int>> stk ;
        
        // to remove extra conditions
        stk.push({'#',0});
        
        for(int i=0;i<n;i++){
            
            // if elements are repeated
            stk.push({s[i] , stk.top().first == s[i] ? stk.top().second + 1 : 1});
            
            // if consecutive match found
            if(stk.top().second == k){
                while(stk.top().first == s[i])
                    stk.pop();
                
			         s.erase(i - k + 1, k);                
			           i -= k;
            }
        }
        
        return s ; 
        
    }
};