class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // We need to store the minimum prod also because 
        // [minimum * -ve element can become max ]
        
        int curr_min = 1  , curr_max = 1 ; 
        int ans = *max_element(nums.begin(),nums.end()) ;
        
        for(int i=0 ;i<nums.size() ;i++){
            
            // it breaks our streak
            if(nums[i] == 0){
                curr_min = 1 ;
                curr_max = 1 ; 
                continue; 
            }
            
            // So values can't be overwritten
            int tmp1 = curr_max * nums[i];
            int tmp2 = curr_min * nums[i];
            
            
            curr_max = max(tmp1 , max(tmp2,nums[i]));
            curr_min = min(tmp1 , min(tmp2,nums[i]));
            
            ans = max(ans,curr_max);
            
        }
        
        return ans ; 
    }
};