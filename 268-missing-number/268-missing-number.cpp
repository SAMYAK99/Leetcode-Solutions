class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int sum = 0  , orz = 0 ;
        for(int i=0 ;i<=nums.size();i++){
            if(i!=nums.size())
                sum += nums[i] ;
            orz += i ;
        }
        
        return  orz - sum ; 
    }
};