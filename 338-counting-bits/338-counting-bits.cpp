class Solution {
public:
    vector<int> countBits(int n) {
        
         vector<int> ans ;
         int val = 0 ;
         
        for(int i=0 ;i<=n ;i++){
           // val =  ;
           //  cout << val << " " ;
            ans.push_back(__builtin_popcount(i));
            // val = 0 ; 
        }
        
        return ans ; 
    }
};