class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end()) ; 
        
        int n = nums.size();
        int mid = n/2 ;
        
        int ans = 0 ; 
        
        // Finding minimum dfference
        for(int i=0 ;i<n ;i++){
            ans += abs(nums[i] - nums[mid]) ; 
        }
        
        return ans  ; 
    }
};