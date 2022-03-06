class Solution {
public:
    int countOrders(int n) {
        
       long long int res = 1 ;
       long long int mod = 1000000007 ;
        
       for(int i=1 ;i<=n ; i++){
           
           // Computing factorial
           res *= i ;
           
           // Avoiding overflow
           res %= mod ;
           
           // Computing next 2*(i-1)
           res *= (2*i-1) ; 
           
            // Avoiding overflow
           res %= mod ;
           
       }
        
        return res%mod ; 
    }
};