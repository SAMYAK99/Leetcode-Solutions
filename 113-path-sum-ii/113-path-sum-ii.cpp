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
    
    
    void findPaths(TreeNode* root , int sum , vector<int> path , vector<vector<int>> &ans){
        
        // Base case
        if(root == NULL)
            return ;
        
        path.push_back(root->val);
        if(root->val == sum & root->left == NULL & root->right == NULL){
            ans.push_back(path);
            path.clear();
            return ; 
        }
        
        // Finding left and right paths
        findPaths(root->left,sum-root->val,path,ans) ; 
        findPaths(root->right,sum-root->val,path,ans) ; 
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans ; 
        
        vector<int> path;
        findPaths(root,targetSum,path,ans) ; 
        return ans ; 
        
    }
};