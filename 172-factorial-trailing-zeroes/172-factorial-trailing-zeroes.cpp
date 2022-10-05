class Solution {
public:
    
    /*
    Zeroes comes from 10 
    Hence we need to find how many times factors of 10 are coming 
    like 2*5 , 10 etc...
    
    and (occurecnes of 2 ) >> (occurences of 5 )
    Hence no. of zeroes : occurences of 5 
    
    */
    int trailingZeroes(int n) {
        
        int ans = 0 ; 
        int p = 5 ;
        
        while(n/p > 0){
            ans += n/p;
            p = p * 5;
        }
        
        return ans ; 
    }
};