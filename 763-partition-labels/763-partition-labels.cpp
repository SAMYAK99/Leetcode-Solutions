class Solution {
public:
    
    /*
    We need to know the last occurecne of every letter
    */
    
    vector<int> partitionLabels(string s) {
    
        // For storing the last occurence of each letter
        map<char,int> mp ;
        vector<int> ans ; 
        
        int n = s.size();
        
        // Finding last occurence
        for(int i=n-1 ;i>=0 ;i--){
            if(!mp[s[i]])
                mp[s[i]] = i ; 
        }
        
      int prev = -1 ;
      int maxi = 0 ;
        
        for(int i=0 ;i<n ;i++){
            // maximum index until partion can be done
            maxi = max(maxi , mp[s[i]]);
            
            // If partition can be done
            if(maxi == i){
                ans.push_back(maxi-prev);
                prev = maxi ;
            }
        }
        
        return ans ; 
        
    }
};