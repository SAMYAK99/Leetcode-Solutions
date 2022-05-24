class Solution {
    
     /*
    obv : 3 : 011
          2 : 010
          5 : 101    (1^0 = 0^1 = 1 ) 
                     1^1 = 0 + left shift carry 1 (this can be identified by using carry op)
    */
    
    
    public int getSum(int a, int b) {
        
        while(b!=0){
            int ans = (a&b) << 1 ; // carry
            a = a^b ; // adding without carry
            b = ans ;  // carry with old a
        }
        
        return a ; 
    }
}