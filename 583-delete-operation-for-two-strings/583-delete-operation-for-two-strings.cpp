class Solution {
public:
    
     int lcs(string &text1, string &text2,int m,int n,int memo[][501]) {
        if(m==0 || n==0){
            return 0;
        }
        if(memo[m][n]!=-1){
            return memo[m][n];
        }
        if(text1[m-1]==text2[n-1]){
            return memo[m][n]= 1+lcs(text1,text2,m-1,n-1,memo);
        }else{
            return memo[m][n]= max(lcs(text1,text2,m-1,n,memo),lcs(text1,text2,m,n-1,memo));
        }
    }
    
    
    int minDistance(string text1, string text2) {
        
        int m=text1.size(),n=text2.size();
        int memo[501][501];
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                memo[i][j]=-1;
            }
        }
        
        int len = lcs(text1,text2,m,n,memo);
        
     // m -> lcs then  lcs -> n
        int ans = m- len + n - len ; 
        
     
        return ans ; 
        
    }
};