class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int n = nums.size();
        int shift = 0 ;
        
        for(int i=0 ;i<n-1 ;i++){
            if(nums[i] == nums[i+1] && ((i+shift) % 2 == 0) )
                shift++;
        }
        
        if((n-shift) % 2 != 0)
            return shift+1;
        else
            return shift ; 
    }
};