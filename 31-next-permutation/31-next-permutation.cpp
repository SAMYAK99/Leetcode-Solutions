class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size() == 0 || nums.size() == 1)
            return ;
        
        long long int n = nums.size();
        long long int i = n-2;
        
        // Finding the breakpoint which is just greater than its previous 
        while(i>=0 && nums[i] >= nums[i+1]){
            i--;
        }
        
    
        // If breakpoint is found 
        if(i>=0){
            long long int j = n - 1 ;
            while(nums[j] <= nums[i]){
                j--;
            }
            
            swap(nums[i],nums[j]);
        }
        
        reverse(nums.begin()+i+1,nums.end()) ;
    }
};