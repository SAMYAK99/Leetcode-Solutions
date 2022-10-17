class Solution {
public:
    int reverse(int x) {
       long int ans = 0;
        
       // reverse 
        while(x != 0) {
            ans = (ans * 10) + (x % 10);
            x = x/10;
        }
        
        // handling negative
        if( ans < INT_MIN || ans > INT_MAX ){
            return 0;
        }
        
        return ans;
    }
};