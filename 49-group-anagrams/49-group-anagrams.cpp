class Solution {
public:
    /*
    Approach 1 : 
    Sort all the strings and store it in map of map<string,vector<string>>
    pushed all the string in resultant vector
    */
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      
        unordered_map<string,vector<string>> mp ;
        int n = strs.size();
         vector<vector<string>> ans ;
        
        // creating a map with key as sorted string and value as vecotr of strings
        for(int i=0 ;i<n ;i++){
            string tmp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(tmp);
        }
        
        for(auto it =mp.begin() ;it!=mp.end();it++){
            ans.push_back(it->second);
        }
        
        return ans ;
    }
};