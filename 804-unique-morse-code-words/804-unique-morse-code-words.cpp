class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        set<string> ans;
        vector<string> morse {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        int n = words.size();
        for(int i=0 ;i<n ;i++){
            string tmp;
            for(int j=0 ;j<words[i].size();j++){
                tmp += morse[words[i][j] - 'a'];
            }
            ans.insert(tmp);
        }
        
        return ans.size();
    }
};