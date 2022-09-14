/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    /*
    ->  To make the numbers Palindrome : Count of frequency of all numbers in path 
      should be even or only 1 odd frequency count is allowed
    ->  Intution : Store the frequency of each charachter and check if it has odd or
       even count freuency
    */
    
    int ans  = 0 ; 
    
    void countFreq(TreeNode* root , unordered_map<int,int> &mp){
        
        if(root == NULL)
            return ; 
        
        // Counting Frequency of each element
        mp[root->val]++;
        
        
        // Reaching at the end of the particular node ie, @ LEAF NODE
        if(root->left == NULL and root->right == NULL){
            int cnt = 0 ; 
            
            for(int i=1 ; i<=9 ;i++){
                if(mp[i] % 2 != 0)
                    cnt++;
            }
            
            if(cnt <= 1)
                ans++;
        }
        
        // Recursive calls
        countFreq(root->left , mp);
        countFreq(root->right ,mp);
        
        // Removing the value of node if we leave the path
        mp[root->val]--;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        unordered_map<int,int> mp ; 
        countFreq(root,mp);
        
        return ans ;
    }
};