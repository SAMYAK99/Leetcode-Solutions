class Solution {
public:
    int maxArea(vector<int>& height) {
        
         // Two pointer approach   
       int l=0,r=height.size()-1;
        int max_area=0;
        
        while(l<r){
            int lh=height[l];
            int rh=height[r];
            
            // calculating max area : Minimum of both the heights * Difference
            max_area=max(max_area,(r-l)*min(lh,rh));
            
            // shifting pointers : lower height container should be shifted further
            if(lh<rh)
                ++l;
            else
                --r;
        }
		
        return max_area;
    }
};