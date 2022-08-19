class Solution {
public:
    bool isPossible(vector<int>& A) {
       unordered_map<int, int> left, end;
        for (int i: A) {
            left[i]++;
        }
        for (int i: A) {
            if (left[i] == 0)
                continue;
            
            left[i]--;
            
            // If one value lesser than the map is present in the array
            if (end[i - 1] > 0) {   
                end[i - 1]--;
                end[i]++;
            }
            // if both the elements present in the map 
            else if (left[i + 1] > 0 && left[i + 2] > 0) {
                left[i + 1]--;
                left[i + 2]--;
                end[i + 2]++;
            } 
            else {   
                return false;
            }
        }
        return true;
    }
};