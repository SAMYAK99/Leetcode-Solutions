class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int i = INT_MAX ;
        int j = INT_MAX ;
        
        for(auto it : nums){
            if(it <= i)              // i is the smallest
                i = it;
            else if (it <= j)        // j is greater than i but lesser than j
                j = it;
            else  
                return true;        // If all condition satisfies  
        }
        
    return false ;
        
    }
};