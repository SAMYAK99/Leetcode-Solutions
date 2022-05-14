class Solution {
public:
    
    /*
    * Approach : 1 (dijstra's Algo)
    -> Minimze the time to reach the node to k
    -> Dijstra's Algorithm  : Single Source Shortest path
    
    * Approach : 2 (BFS)
    -> Traverse the graph and update distance values
    -> Find max distance if all the nodes is visited 
    -> Time Complexity : O(V+E)
    
    */
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
       vector<pair<int,int>> adj[n+1];
        vector<int> dist(n+1,INT_MAX) ; 
        
        // Adjacency matrix
        for(int i=0; i<times.size() ;i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        queue<int> q ;
        q.push(k);
        
        // Marking the intial dist as 0 
        dist[k] = 0 ; 
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            
            for(pair<int,int> it : adj[curr]){
               if(dist[it.first] > dist[curr]+it.second){
                    dist[it.first]=dist[curr]+it.second;
                    q.push(it.first);
                } 
                
            }   
          
        }
        
        
        int res = 0 ; 
        for(int i=1 ;i<dist.size();i++){
            
            // 1 node left unvisited
            if(dist[i] == INT_MAX)
                return -1; 
            
            res = max(res , dist[i]);
        }
            
        return res ;         
        
    }
};