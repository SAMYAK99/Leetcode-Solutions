class Solution {
public:
    
    // Simple Brute Force (DP) Approach
    
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        
        // what is the last value i can reach
        int last = n-1 ; 
        
        for(int i=n-2 ;i>=0 ;i--){
          // from every ith check weather i can reach to end from the latest last postion  
         if(i + nums[i] >= last)
            last = i ; 
        }
        
        return (last == 0 ); 
    }
};