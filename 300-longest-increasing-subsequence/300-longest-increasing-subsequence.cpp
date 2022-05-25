class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==0)
            return 0 ;
        
        if(n==1)
            return 1 ;
        
        // Atleast 1 sequece will be our answer
        int mx = 1 ; 
        vector<int> lis(n+1 ,1 );
        
        for(int i=1 ;i<n ;i++){
            for(int j=0 ;j<i; j++){
                if(nums[i] > nums[j] && lis[i] <= lis[j])
                      lis[i] = lis[j] + 1 ;
                
                mx = max(mx,lis[i]) ;
            }
        }
        
        return mx ; 
    }
};