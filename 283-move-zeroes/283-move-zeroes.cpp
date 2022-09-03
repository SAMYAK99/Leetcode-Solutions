class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int l = n-1 ; 
        
        int cnt = 0 ; 
        int tmp = 0 , i ; 
        
        for( i=0 ;i<n ; i++){
            if(nums[i] != 0)
                nums[tmp++] = nums[i];
        }
        
        for( ; tmp<n ; tmp++)
            nums[tmp] = 0 ; 
        
    }
    
};