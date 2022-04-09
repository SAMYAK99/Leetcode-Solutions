class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int size = coins.size();
        
        
        int dp[size+1][amount+1];
        
       
        // Intialization
         for(int i=0 ; i<size+1 ;i++){
             for(int j=0 ; j<amount+1 ; j++){
                 
                 //when no coins to make amount
                 if(i==0)
                     dp[i][j] = 0 ; 
                 
                 //when 0 amount to be made
                 if(j==0)
                     dp[i][j] = 1 ; 
             }
         }
        
        // DP Traversal
         for(int i=1 ; i<size+1 ;i++){
             for(int j=1 ; j<amount+1 ; j++){
                 //Incude or Exclude
                 if(coins[i-1] <= j){
                     dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]] ; 
                 }
                 else
                     dp[i][j] = dp[i-1][j] ; 
               
             }
         }
        
        return dp[size][amount] ; 
    }
};