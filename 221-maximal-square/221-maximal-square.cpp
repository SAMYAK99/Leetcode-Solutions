class Solution {
public:
    
    /*
    A matrix will be square only when its row , columns and diagonal are 1 
     1  -> 1 
     1     1
     
    We need to keep track weather the adjacent matrixes were a part of larger matrix
     
    Hence dp can be applied
    */
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        
        if(m == 0)
            return 0 ; 
        
        int n = matrix[0].size();
        int res = 0 ; 
        
        int dp[m+1][n+1] ; 
        
        // Intialization with all 0's
        for(int i=0 ;i<=m;i++){
            for(int j=0 ; j<=n ;j++){
                    dp[i][j] = 0 ; 
            }
        }
        
        for(int i=1 ;i<=m ;i++){
            for(int j=1 ;j<=n ;j++){
              if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = 1 + min( {dp[i-1][j-1]  ,dp[i-1][j],dp[i][j-1]} ) ; 
                }
                // Maximum until mat[i][j]
                res = max(res , dp[i][j]) ; 
            }
        }
        
       
       // Returning the maximum square of side * side 
        return res*res ;
    }
};