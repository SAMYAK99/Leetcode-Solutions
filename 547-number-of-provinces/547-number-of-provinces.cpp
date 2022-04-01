class Solution {
public:
    
    // Simple DFS 
    // Check connrected components
    
    void dfs(vector<int> &vis ,vector<vector<int>>& nums ,int i){
      
        vis[i] = 1 ; 
        
        for(int j=0 ; j<nums[i].size() ; j++){
            if(nums[i][j] == 1 && !vis[j])
                dfs(vis , nums , j );
        }
    }

    
    
    int findCircleNum(vector<vector<int>>& nums) {
        
      int n = nums.size() ;   
      vector<int> vis(n,0);
      int ans = 0 ; 
        
        for(int i=0 ;i<n ;i++){
            if(!vis[i]){
                dfs(vis,nums,i);
                ans++;
            }
        }
        
        
        return ans ; 
    }
};