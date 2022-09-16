class Solution {
public:
    /*
    -> Classical DP Problem
    */
    
      vector<vector<int>> dp;
    
    int solve(vector<int>& nums, vector<int>& multi , int i , int n , int k){
        
        // base case
        if(k == multi.size())
            return 0 ;
        
        // memoization
        if(dp[i][k] != INT_MIN)
            return dp[i][k];
        
        // Take from either left or right of the array
        int x = solve(nums,multi , i+1 , n ,k+1) + nums[i] * multi[k];
        int y = solve(nums,multi, i , n , k+1) + (nums[(n-1)-(k-i)]*multi[k]) ;
        
        return dp[i][k] = max(x,y) ; 
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        
        int n = nums.size() ;
        int m = multi.size();
        
      dp.resize(m+1,vector<int>(m+1,INT_MIN));
        
        return solve(nums,multi,0,n,0);
     
        
    }
};