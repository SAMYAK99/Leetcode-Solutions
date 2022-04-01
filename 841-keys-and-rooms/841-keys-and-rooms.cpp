class Solution {
public:
    
    // Simple BFS
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size() ; 
        vector<int> vis(n,0);
        queue<int> q ; 
        
        vis[0] = 1 ; 
        
       for(int i=0;i<rooms[0].size();i++){
            q.push(rooms[0][i]);
        }
        
     
        
        // BFS Traversal
        while(!q.empty()){
           int j = q.front();
            q.pop();
            while(!vis[j]){
                vis[j] = 1 ; 
                 for(int i=0;i<rooms[j].size();i++){
                    q.push(rooms[j][i]);
                }
            }
                
        }
        
      // If any visited array can't be visited   
        for(auto x : vis){
            if(x == 0)
                return false ; 
        }
        
        return true ; 
        
    }
};