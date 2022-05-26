class Solution {
public:
    
    int dp[301] ; 
    
    int help( set<string> st , int i , string s){
        
        // base case : If we reach the end of string
        if(i == s.size())
            return 1 ;
        
        string tmp ; 
        if(dp[i] != -1)
          return dp[i];
        
        else{
            for(int j = i ;j<s.size() ;j++){
                tmp+=s[j];
                // If given word is found in set
                if(st.find(tmp) != st.end())
                  // Recursive case 
                    if(help(st,j+1,s))  return  dp[i] = 1 ; 
            }
        }
        
        return dp[i] = 0 ; 
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        memset(dp,-1,sizeof dp);
        set<string> st ; 
        
        // For searching 
        for(auto a : wordDict)
            st.insert(a);
        
        
       return help(st , 0 , s );
        
    }
};