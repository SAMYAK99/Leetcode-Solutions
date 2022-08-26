class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string N_str = sortedNum(n);
        for(int i=0 ; i <32 ;i++){
            // Checking with every power of 2
            if(N_str == sortedNum(1<<i))
                return true;
        }
        
        return false ;
    }
    
    string sortedNum(int n){
        string res = to_string(n);
        sort(res.begin(),res.end());
        return res ; 
    }
};