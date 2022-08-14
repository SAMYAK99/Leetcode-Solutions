class Solution {
public:
    
    /*
    For Finding smallest path we find use BFS 
    Edge can be formed b/w 2 nodes if there is a difference of one charachter b/w them
    
    */
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
     
        // if endword is not present in wordlist
        if(find(wordList.begin(),wordList.end(),endWord) == wordList.end())
            return 0;
        
        // Removing Duplicates word from wordList
        set<string> st;
        for(auto it : wordList){
            st.insert(it);
        }
        
        int depth = 0 ;   // Contains our answer
        
        // Simple BFS Traversal
        queue<string> q ;
        q.push(beginWord);
        
        while(!q.empty()){
            int n = q.size();
            depth++;
            
           while(n--){
                string curr = q.front();
                q.pop();
               
                // Checking each word : chrachter by character 
                for(int i=0;i<curr.length();i++){
                    
                    string tmp = curr;
                    for(char c='a';c<='z';c++){
                        tmp[i]=c;
                        
                        if(tmp==curr) continue;
                        
                        // If our final word is found
                        if(tmp==endWord)  return depth+1;
                        
                        // If a word is found from the set
                        if(st.find(tmp)!=st.end()){
                            q.push(tmp);
                            st.erase(tmp);
                        }
                    }
                }
                
            }
            
        }
        
        // If no match found
        return 0;
        
    }
};