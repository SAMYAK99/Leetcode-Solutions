class Solution {
public:
    
    /*
    -> For calculating in neighbours divide the array in left and right 
       and traverse them independently
    */
    
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> left(n,1) , right(n,1) ;
        
        // Traversing the left array and find maximum in left
        for(int i=1 ;i<n ;i++){
            if(ratings[i] > ratings[i-1] )
                left[i] = left[i-1] + 1 ; 
        }
        
        // Traversing the right array and find maximum in left
        for(int i=n-1 ;i>0 ;i--){
            if(ratings[i-1] > ratings[i] )
                right[i-1] = right[i] + 1 ; 
        }
        
        int ans = 0 ; 
        for(int i=0 ;i<n ;i++){
            ans += max(left[i],right[i]);
        }
        
        return ans ; 
    }
};