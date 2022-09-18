class Solution {
public:
    int trap(vector<int>& height) {
        
       int n = height.size();
        
      int vleft[n]  , vright[n] ; 
        
        vleft[n-1] = height[n-1] ; 
        vright[0] = height[0] ; 
         int low = -1;
        
        
        for(int i=1 ; i<n ; i++){
             vright[i] = max( vright[i-1] , height[i]);
           
        }
        
        
        low = -1 ; 
        
       for(int i=n-2 ; i>=0 ; i--){
               vleft[i] = max( vleft[i+1] , height[i]);
           
        }
        
        int sum = 0 ; 
    
          
           for(int i=0 ; i<n ; i++){
               sum += (min(vleft[i],vright[i]) - height[i]) ; 
          }
        
        return sum ; 
    }
};