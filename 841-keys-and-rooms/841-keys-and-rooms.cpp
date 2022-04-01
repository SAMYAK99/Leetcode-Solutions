class Solution {
public:
    
    // By Simple DFS Call
    
    void dfs(vector<vector<int>>& rooms  , vector<int> &vis , int i){
        vis[i] = 1 ; 
        
       for(auto it : rooms[i]){ 
        if(!vis[it])
        dfs(rooms,vis,it);
       }
        
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size() ; 
        vector<int> vis(n,0);
       
         // vis[0] = 1 ; 
        dfs(rooms , vis , 0);
        
      // If any visited array can't be visited again return false
        for(auto x : vis){
            if(x == 0)
                return false ; 
        }
        
        return true ; 
        
    }
};