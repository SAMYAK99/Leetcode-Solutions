class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int ans = 0 ;
        int low = 0 , high = nums.size() -1 ; 
        
        sort(nums.begin() , nums.end()) ; 
        
        while(low < high){ 
            int val = nums[low] + nums[high] ;
            if(val == k){
                ans++;
                low++;
                high--;
            }
            else if(val > k){
                high--;
            }
            else{
                low++;
            }
        }
        
        return ans ; 
    }
};