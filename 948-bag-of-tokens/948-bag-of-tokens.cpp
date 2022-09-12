class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(),tokens.end());
        int ans = 0 ;
        
      
        int i=0 ;
        int j = tokens.size()-1 ; 
        
        
       while(i<=j){
            
             if(tokens[i] <= power){
                power -= tokens[i++];
                ans++;
            }
            else if(ans >= 1  and i < j){
                power += tokens[j--];
                ans--;
            }
            else
                break ;
        }
        
        return ans ; 
    }
};