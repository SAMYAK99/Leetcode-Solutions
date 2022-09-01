class Solution {
public:
    
    // Dynamic Programming : Tabulation
    
    int fib(int n) {
       
        vector<int> dp(n+1) ; 
      
        // base case
        if(n<=1)
            return n ;
        
         dp[0] = 0 ;
         dp[1] = 1 ;
        
        
       for(int i=2 ;i<=n ;i++)
        dp[i] = dp[i-1] + dp[i-2] ;
        
        return dp[n] ; 
    }
};