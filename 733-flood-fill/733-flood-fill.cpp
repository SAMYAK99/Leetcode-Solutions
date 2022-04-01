class Solution {
public:
    
      void  dfs(vector<vector<int>>& image , int sr , int sc ,int color , int oldColor){
        if(sr<0 || sc < 0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc] != oldColor){
            return ;
        }
       
     
       
       // Marking the node visited
       image[sr][sc] = color;
         
         dfs(image , sr+1 , sc , color  , oldColor);
         dfs(image , sr , sc+1 ,color  , oldColor);
         dfs(image , sr-1 , sc ,color  , oldColor);
         dfs(image , sr , sc-1 ,color  , oldColor);
         
    }
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
       if(image[sr][sc] == newColor)
           return image ; 
        
        dfs(image , sr , sc , newColor , image[sr][sc]);
        
        return image ; 
    }
};