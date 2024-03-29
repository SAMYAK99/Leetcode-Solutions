class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        /*
        search if there exists an index in s, for each character of given
        word, that's greater than the index found for previous charcter.    
        */
        
        
        int ans = 0;
        vector<vector<int>> mappings(26);  
        
        // stores array of indices for each character in s
        for(int i = 0; i < size(s); i++)
            mappings[s[i] - 'a'].push_back(i);
        
        
        for(auto& word : words) {
            bool found = true;
            // i = index in word | prev = index in s matched for word[i-1]
            for(int i = 0, prev = -1; found && i < size(word); i++) {
                auto& v = mappings[word[i]-'a'];
                 // check if current character exists in s with index > prev : for lcs
                auto it = upper_bound(begin(v), end(v), prev);  
                   // doesn't exist
                if(it == end(v)) 
                    found = false;   
                  // update prev for next check
                else prev = *it;                         
            }
            ans += found;
        }
        return ans;
    }
};