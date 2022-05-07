class Solution {
public:
    

    string shortestCommonSupersequence(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        string res ; 
    
        // table generated for dp
        int mat[1001][1001];
        
        // lcs
        for(int i=0 ;i<=n ;i++){
            for(int j=0 ;j<=m ;j++){
               if(i==0||j==0)
                  mat[i][j]=0;
               else if(s1[i-1]==s2[j-1]){
                  mat[i][j]=1+mat[i-1][j-1];
                }
               else{
                  mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
               }
            }
        }
        
         //print lcs
    int i=n,j=m;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            res.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(mat[i-1][j]>mat[i][j-1]){
                res.push_back(s1[i-1]);
                i--;
            } else{
                res.push_back(s2[j-1]);
                j--;
            }
        }
    }
    while(i>0) // if s1 characters are still left
    {
        res.push_back(s1[i-1]);
        i--;
    }
    while(j>0) //if s2 characters are still left
    {
        res.push_back(s2[j-1]);
        j--;
        
    }
        
        reverse(res.begin(),res.end()); 
        return res;     
        
    }
    
    
};