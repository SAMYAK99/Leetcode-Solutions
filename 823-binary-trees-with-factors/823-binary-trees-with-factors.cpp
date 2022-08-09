class Solution {
public:
    
      // Scan every element and store it in dp array , 
      // how many binary tree can be formed by keeping the current node as the root node
    
    /*
    BLOG : https://www.coderscamp.tech/post/binary-trees-with-factors
    */
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        int n = arr.size();
        int mod = 1000000000 + 7 ;
        sort(arr.begin(),arr.end());
        
        vector<long> dp(n,1);
        map<int,int> mp ;
        
        for(int i=0 ;i<n;i++)
            mp[arr[i]] = i ;
     
        
        for(int i=0 ;i<n ;i++){
            for(int j=0 ;j<n ;j++){
                if(arr[i] % arr[j] == 0){   // If arr[j] is a factor of arr[i]
                    int idx = arr[i] / arr[j] ;  // finding the index 
                    if(mp.find(idx) != mp.end()){  // if index is present then ans will be 
                         dp[i]=(dp[i]+dp[j]*dp[mp[idx]])%mod;  // left tree * right tree
                    }
                }
                    
            }
        }
        
         long int  ans=0;
        for(long x:dp)
            ans+=x;
        
        return (int)(ans%mod);
        
    }
};