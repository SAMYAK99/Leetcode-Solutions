class Solution {
public:
    
    // Sum of all element must be even 
    // If the sum is odd partion cant be done in 2 equal halves
    
    bool subsetSum(vector<int>& nums ,int sum ){
       
        int n = nums.size();
        
        // DP Matrix
        bool dp[n+1][sum+1];
        
        //Intialsation
        for(int i=0 ; i<n+1 ;i++){
            for(int j=0 ; j<sum+1 ;j++){
                // make sum with 0 elements : not possible
                if(i == 0 )
                    dp[i][j] = false ; 
                
                // make 0 sum with given matrix : possible
                if(j == 0)
                    dp[i][j] = true ; 
            }
        }
        
       // MAX => OR
       // weight array => i
       // sum => j
        
        for(int i=1 ; i<n+1 ;i++){
            for(int j=1 ;j<sum+1 ;j++){
                // include or exclude
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j] ; 
                // exclude
                else
                    dp[i][j] = dp[i-1][j] ; 
            }
        }
        
        return dp[n][sum] ; 
    }
    
    
    
    bool canPartition(vector<int>& nums) {
        
         int sum = 0 ;
        
        for(int s : nums)
            sum += s;
        
        if(sum % 2 != 0)
            return false;
        
         // find a subset whose sum should be equal to sum/2
        else
           return subsetSum(nums , sum/2);   
        
    }
};