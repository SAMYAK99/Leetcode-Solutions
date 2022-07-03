class Solution {
public:
    string decodeMessage(string key, string m) {
        
        
        
       vector<char> map(26);
       int k =0 ;  
    
    //create mapping
    for(auto i:key){
        // current is not a space and is not found before
        if(i!=32 and !map[i-'a']) map[i-'a']= (k+'a') , k++;
	}
    
    //then update characters inplace in message string according to mapping except for spaces
    for(int i=0;i<m.size();i++) if(m[i]!=32) m[i]= map[m[i]-'a'];
    return m;
    }
};