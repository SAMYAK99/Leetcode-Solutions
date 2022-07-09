class Solution {
public:
    int jump(vector<int>& nums) {
        
        
        int end = 0 , farthest = 0 ;
        int jump = 0 ; 
        
        for(int i=0 ;i<nums.size()-1 ;i++){
            
            // from the current index , how far can we reach
            farthest = max(farthest , i + nums[i]);
            
            if(i == end){
                end = farthest ;
                jump ++ ; 
            }
        }
        
        return jump ; 
    }
    
};