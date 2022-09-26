class Solution {
public:
    
    /*
    Simple Union Find : Disjoint Set
    
    Find : (recu) 
    Union(x,y) : uf[x] = y 
    
    */
    
    int uf[26] ; 

    int find(int x){
         return uf[x] == x ? x : (uf[x] = find(uf[x]));
    }
    
    
    bool equationsPossible(vector<string>& eq) {
        
        // Intialization 
        for(int i=0 ; i<26 ; i++)
            uf[i] = i ; 
        
        // If "==" put in same set (e[0],e[3]) otherwise put in differnt set
        for(auto e : eq){
            if(e[1] == '=')
                uf[find(e[0] - 'a')] = find(e[3] - 'a'); 
        }
        
        // If ! and == are in same set return false 
        for(auto e : eq){
            if(e[1] == '!' and  uf[find(e[0] - 'a')] == find(e[3] - 'a'))
                return false ;
        }

        return true ; 
       
    }
};