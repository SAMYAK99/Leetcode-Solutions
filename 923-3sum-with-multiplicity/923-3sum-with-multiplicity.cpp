class Solution {
public:
    
    /*
       nCr = n! / r! * (n-r)!
       
     i == j == k : n! / 3!(n-3)! => [ n * (n-1) * (n-2) / 6 ]
     i == j != k : n! / 2!(n-2)! * c[k] => [ c[k] ]
     i != j != k : c[i] * c[j] * c[k] 
     
    */
    
    int threeSumMulti(vector<int>& A, int target) {
        
         unordered_map<int, long> c;
        for (int a : A)
            c[a]++;
        long res = 0;
        
        for (auto it : c)
            for (auto it2 : c) {
                int i = it.first, j = it2.first, k = target - i - j;
                if (!c.count(k)) continue;
                if (i == j && j == k)
                    res += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
                else if (i == j && j != k)
                    res += c[i] * (c[i] - 1) / 2 * c[k];
                else if (i < j && j < k)
                    res += c[i] * c[j] * c[k];
            }
        
        return res % int(1e9 + 7);
    }
};