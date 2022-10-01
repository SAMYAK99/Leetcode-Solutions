class Solution {
public:
    
    // Classical DP Problem 
    /*
     at every index in the string we have got 2 choices :

Pick only current element as a single value between [1-9]
Pick 2 elements i.e current as well as next element to make a couple. This value will be [10, 26]
    
    */
    
    int dp[102];
    
    int decode(string s , int idx , int n){
        
        // base case 
        /*
        If current element is 0, we simply return 0 as it is not possible to get
        a character using 0. Zero will only be used in couple with some number 
        occuring before it. Ex : 1 0 , or 2 0 
        */
        
        if(idx < n and s[idx] == '0')
            return 0 ;
        
        if(idx >= n)
            return 1 ;
        
        // Memoziation
        if(dp[idx] != -1)
            return dp[idx] ;
        
        // Storing final answer
        int ways = 0 ; 
        
        // Picking single
      ways = decode(s, idx+1, n);
        
       // Pick couple : Checking ranges of 1 to 19 + 20 - 26
        if(idx+1 < n && ((s[idx] == '1' && s[idx+1] <= '9') || (s[idx]=='2' && s[idx+1] < '7')))
           ways += decode(s, idx+2, n);
           
        return dp[idx] = ways; 
        
    }
    
    int numDecodings(string s) {
     
         int n = s.size();
        memset(dp, -1, sizeof(dp));
        
         return decode(s , 0 , n) ;
      
    }
};