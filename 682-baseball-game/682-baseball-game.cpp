class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack <int> q ;
        
        
        int n = ops.size();
        
        for(int i=0 ;i<n;i++){
            
            if(ops[i] != "D" && ops[i] != "C" && ops[i] != "+"){
                int val = stoi(ops[i]) ;
                q.push(val);
            }
            
            else if(ops[i] == "D"){
                int val = q.top();
                val *= 2 ;
                q.push(val);
            }
            
            else if(ops[i] == "+"){
                 int val1 =  q.top();
                 q.pop();
                 int val2 = q.top();
                 q.push(val1);
                 q.push(val1+val2);
            }
            
            else  if(ops[i] == "C"){
                q.pop();
            }
            
            // cout << q.front() << " " ; 
            // cout << endl ;
        }
        
        int ans = 0 ; 
        while(!q.empty()){
            ans +=  q.top();
            q.pop();
        }
        
        return ans ; 
    }
};