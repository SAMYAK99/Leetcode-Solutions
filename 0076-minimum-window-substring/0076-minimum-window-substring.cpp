class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> map1 , map2;
        
        // Frequency count of second string
        for(auto it : t)
            map1[it]++;
        
         
         int check=INT_MAX;
         string result;

        int slow=0,fast=0,lettercounter=0;
        
        for(;fast<s.length();fast++){
            char ch=s[fast];
            
            // EXPANDING
            // If current char is present in first map add it in second map
            if(map1.find(ch)!=map1.end()){
                map2[ch]++;
            
            // Increase the letter count frequency   
            if(map2[ch]<=map1[ch])
                lettercounter++;
                
            }
            
            // SHRINKING
            if(lettercounter>=t.length()){
                
                while(map1.find(s[slow])==map1.end()||map2[s[slow]]>map1[s[slow]]){
                    map2[s[slow]]--;
                    slow++;
                }
                if(fast-slow+1<check){
                    check=fast-slow+1;
                    result=s.substr(slow,check);
                }
            }
        }
        return result;
    }
};