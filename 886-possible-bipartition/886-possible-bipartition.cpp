class Solution {
public:
    
    // -> Same as Is Graph Bipartite
    
    // Bipartite Graph : No 2 adjacent nodes should have same color
    // Odd Vertex Cycle cannot be a Bipartite Graph
    // Graph Coloring : 1 = Blue Color , -1 = Orange Color , 0 = Uncolored
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
         vector<int> graph[n + 1];
		//graph adj generation using given vector<vector<int>>dislikes
		for (auto i : dislikes){
			graph[i[0]].push_back(i[1]);
			graph[i[1]].push_back(i[0]);
		}
        
        
        // int n = graph.size();
        vector<int> vis(n+1,0);
       
        
        // For all Components
        for(int i=1 ; i<=n ; i++){
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