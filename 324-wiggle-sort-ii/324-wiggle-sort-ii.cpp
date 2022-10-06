class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
       
       sort(nums.begin(),nums.end());
        vector<int> tmp(n) ;
        
       int i = 1 , j = n-1;
        
      //For odd Indexes
        while(i < n){
            tmp[i] = nums[j];
             j--;
             i+=2;
        }
        
      // For even Indexes
        i = 0 ;
        while(i < n){
            tmp[i] = nums[j];
            j--;
            i+=2;
        }
     
     // Assigning the same values   
        for(int i=0 ;i<n;i++)
          nums[i] = tmp[i];
    }
};