class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int ans = 0 ; 
        int n = nums.size() ; 
        vector<int> tmp(n) ;
        
        for(int i = 0 ; i<n ; i++)
             tmp[i] = nums[i];
        
        sort(tmp.begin(),tmp.end());
        
        int spos = -1 , epos= -1 ;
        
        for(int i=0 ;i<n;i++){
            if(tmp[i]!=nums[i]){
                spos = i ;
                break;
            }
        }
        
         for(int i=n-1 ;i>=0 ;i--){
            if(tmp[i]!=nums[i]){
                epos = i ;
                break;
            }
        }
        
         ans = epos - spos + 1 ;
        
        if(spos == -1 && epos == -1)
            return  0 ;
        
        else 
            return ans ; 
        
    }
};