class Solution {
public:
   
    vector<string> mapping = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    
    void findCombination(  vector<string> &res , string dig , string val , int i){
         if (i == dig.size()) {
            res.push_back(val);
            return;
        }

        int d = dig[i] - '0';
        for (char ch : mapping[d]) {
            findCombination(res , dig , val + ch, i + 1);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        
         vector<string> res ; 
         if(digits.size() == 0 )
             return res ; 
        
        findCombination(res , digits , "" , 0 );
        
        return res; 
    }
};