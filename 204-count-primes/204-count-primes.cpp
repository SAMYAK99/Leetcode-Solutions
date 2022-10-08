class Solution {
public:
    int countPrimes(int n) {
        
        
        if(n<2)
            return 0;
        
        
        int cnt = 0 ;
        vector<bool> isPrime(n , true);
        
        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int i=2 ; i*i < n ; i++){
            if(isPrime[i]){
                for(int j = i*i ; j<n ;j = j+i)
                    isPrime[j] = false;
            }
        }
        
        for(int i=2 ;i <isPrime.size();i++){
            if(isPrime[i])
                cnt++;
        }
        
        return cnt; 
        
    }
};