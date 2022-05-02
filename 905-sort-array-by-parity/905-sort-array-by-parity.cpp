class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
         list<int>  ans ; 
          vector<int> v;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i] & 1) ans.push_back(nums[i]);
            else ans.push_front(nums[i]);
        }
        
        for(int i : ans)
            v.push_back(i);
        
        
        return v ; 
        
    }
};