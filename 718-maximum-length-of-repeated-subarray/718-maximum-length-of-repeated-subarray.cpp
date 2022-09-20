class Solution {
public:
    /*
    Similar to LCS
    */
    
   int ans = 0 ; 
    int lcs(int m , int n ,vector<int>& nums1, vector<int>& nums2){
        
         int dp[m+1][n+1];
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0)
                    dp[i][j]=0;
            }
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1 ;j<n+1;j++){
                if(nums1[i-1] == nums2[j-1]){
                   dp[i][j]= 1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);   
                }
                else{
                     dp[i][j] = 0 ;     
                }
            }
        }
        
        return ans ; 
    }
                                             
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
 
         int m = nums1.size();
         int n = nums2.size();
        
       
        
        return  lcs(m,n,nums1,nums2);
        
    }
};