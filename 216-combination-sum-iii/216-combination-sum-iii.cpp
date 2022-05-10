class Solution {
public:
    
     vector< vector<int> > ret;
    
    void rec(int count, int k, int n, int sum, vector<int>tmp, int start){
        if(k == count){
            if(n == sum){
                ret.push_back(tmp);
            }
            return;
        }
        if(start > 9) return;
        tmp.push_back(start);
        rec(count+1, k, n, sum+start, tmp, start+1);
        tmp.pop_back();
        rec(count, k, n, sum, tmp, start+1);
            // rec(k, n, sum, tmp, i+1);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
          vector<int>tmp;
        rec(0, k, n, 0, tmp, 1);
        return ret;
    }
};