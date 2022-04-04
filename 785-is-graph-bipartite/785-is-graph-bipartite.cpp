class Solution {
public:
    
    // Bipartite Graph : No 2 adjacent nodes should have same color
    // Odd Vertex Cycle cannot be a Bipartite Graph
    // Graph Coloring : 1 = Blue Color , -1 = Orange Color , 0 = Uncolored
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> vis(n,0);
       
        
        // For all Components
        for(int i=0 ; i<n ; i++){
            // Alredy Coloured : Skip
            if(vis[i]==1 || vis[i] == -1)
                continue;
            
               queue<int> q ; 
            // Marking the first color
              vis[i] = 1 ;
                q.push(i);
            
            // BFS Call
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(auto adj : graph[curr]){
                    // If adjacent node is uncolored , mark with opposite colors
                    if(vis[adj] == 0 ){
                        vis[adj] = -vis[curr] ; 
                        q.push(adj);
                    }
                    
                     // Both the adjacent nodes have same color  
                    if(vis[adj] == vis[curr])  
                     return false ; 
                }       
            }        
        }
        
        return true ; 
    }
};