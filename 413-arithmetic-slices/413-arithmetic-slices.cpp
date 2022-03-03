class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size() ; 
        if(n <=2)
            return  0 ;
        
        // Pattern Formed : 1 3 6 10 
        int ans = 0   ,cnt = 0 ;
        
        for(int i=0 ;i<n-2 ;i++){
            if(nums[i+2]-nums[i+1] == nums[i+1] - nums[i])
                cnt++;     
            else {
                ans += (cnt * (cnt + 1 )) / 2  ;
                cnt = 0 ;
            }
        }
        
        if(cnt != 0 )
             ans += (cnt * (cnt + 1 )) / 2  ;
        
            return ans ; 
    }
};