class Solution {
public:
    
    /*
    Similar to printing longest common subsequence
    */
    
    int minDistance(string word1, string word2) {
    
         int m = word1.size();
         int n = word2.size();
        
        int dp[m+1][n+1] ;
        
        // Intialzation
        for(int i=0 ; i<m+1 ; i++){
            for(int j=0 ; j<n+1 ; j++){
               // If first string is empty, only option is to insert all characters of second string  
                if(j==0)
                     dp[i][j] = i ;
                // If second string is empty, only option is to insert all characters of first string   
                if(i==0)
                    dp[i][j] = j ;
            }
        }
        
        // DP
        for(int i=1 ; i<m+1 ;i++){
            for(int j=1 ;j<n+1 ;j++){
                if(word1[i-1] == word2[j-1]){
                    //if characters at current position in 2 strings are equal
                    //there will be no new operation so copy value from previous position
                    dp[i][j] = dp[i-1][j-1] ;
                }
               // If the last character is different, consider all 
               // possibilities and find the minimum
                else{
                    dp[i][j] = 1 + min({dp[i][j - 1], // Insert 
                                   dp[i - 1][j], // Remove 
                                   dp[i - 1][j - 1]}); // Replace 
            }
            }
        }
        
        
        return dp[m][n] ; 
    }
};