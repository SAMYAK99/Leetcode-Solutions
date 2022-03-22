class Solution {
public:
    
    // House robber 1 for adjacent solutions
    int solve(vector<int> nums) {
          int n=nums.size();
        
        if(n==0)
            return 0;
        
        vector<int>dp(n);
        
        if(n>=1)
            dp[0]=nums[0];
        
        if(n>=2) dp[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
           dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
       return dp[n-1];    
    }
    
    
    int rob(vector<int>& nums) {
        
        // BASE CASE
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
         
        // Either take 1st house or last house
          return max(solve(vector<int>(nums.begin(),nums.end()-1)),solve(vector<int>(nums.begin()+1,nums.end())));
       
    }
};