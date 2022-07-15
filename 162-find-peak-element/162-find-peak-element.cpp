class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int val = *max_element(nums.begin(),nums.end());
        for(int i=0 ;i<nums.size();i++){
            if(nums[i] == val){
                return i ;
               break ;
            }
        }
        
        return 0 ;
    }
};