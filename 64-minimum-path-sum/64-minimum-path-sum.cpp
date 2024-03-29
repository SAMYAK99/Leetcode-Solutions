class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
     
        
      // Intialzation  
      vector<vector<int> > dp(m, vector<int>(n, grid[0][0]));
        
      // For no columns  
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        
      // For No rows  
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        
        for(int i=1 ; i<m ;i++){
            for(int j=1 ;j<n ;j++){
               
                dp[i][j] = grid[i][j] +  min(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        return dp[m-1][n-1] ; 
    }
};