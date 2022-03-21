class Solution {
public:
    
     // Classical DP Problem
    
    int rob(vector<int>& nums) {
        
        int n = nums.size() ; 
        
        // Base Case
        if(n==0)   return 0;
        if(n==1)   return nums[0];
        if(n==2)   return max(nums[0],nums[1]) ; 
        
        // DP Array
         vector<int> dp(n);
        
        dp[0] = nums[0] ;
        dp[1] =  max(nums[0],nums[1]) ; 
        
        // Calculating maximum profit until Nth house
        
        for(int i=2 ; i<n ; i++){
            // Maxium profit =  current house + Previous alternate house  OR previous house
            // for Eg in 3 : eiher (1,3) OR (2)
            dp[i] = max( nums[i]+ dp[i-2] , dp[i-1]) ; 
           
        }
        
        
        return dp[n-1];
    }
};