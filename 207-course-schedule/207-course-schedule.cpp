class Solution {
public:
    
    /*
     Deadlock detection
     If we have cycle in a graph then there is a deadlock
     Hence this problem reduces to check weather there is cycle or not
     See if it is DAG or Not : Topological Sort
     */
    
    /*
    visited vector denotes whether a node has been visited or not
    dfsVisited vector will denote whether the node has been visited IN THE CURRENT DFS CALL OR NOT.
    Cycle if :  visited[node] == 1 & dfsVisited[node] == 1,
    */
    
    
     bool checkDFS(int node, vector<int>& visited, vector<int>& dfsVisited, vector<int> adj[]) {
      
         visited[node] = 1;
         
      // For backtracking recursion calls   
        dfsVisited[node] = 1;
       
         
         // Traversing all the adjacent nodes
        for(auto it : adj[node]) {
            if(visited[it] == 0) {
                if(!checkDFS(it, visited, dfsVisited, adj)){
                    return false;   
                }
            } else if(dfsVisited[it] == 1){
                return false;
            }
        }
        
       //  Backtracking the recursion calls and make current node dfs unvisted 
        dfsVisited[node] = 0;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        // Making adjancency lists
        for(int i = 0; i < prerequisites.size(); i++) {
            int v = prerequisites[i][0], u = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> visited(numCourses, 0);
        vector<int> dfsVisited(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0) {
                if(!checkDFS(i, visited, dfsVisited, adj)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};