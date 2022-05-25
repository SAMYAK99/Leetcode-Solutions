class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int dp[m][n];
        
        // Assume star will be going to Robot
        for(int i=0 ;i<m ;i++){
            for(int j = 0 ;j<n ;j++){
                
                // Only 1 unique path is possible for 1st row and 1st column
                if(i==0 || j==0)
                    dp[i][j] = 1 ;
                
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        
        return dp[m-1][n-1];
    }
};