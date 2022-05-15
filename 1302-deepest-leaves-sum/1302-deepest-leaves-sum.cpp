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
    
    int sum = 0 ; 
   
    // Finding max depth
    int maxDepth(TreeNode* root){
        
        if(root == NULL)
            return 0 ;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return max(left,right) + 1 ; 
        
    }
    
    // Finding leaves sum
    void findSum(TreeNode* root , int curr ,int dp){
        if(root == NULL)
            return ; 
        
        if(root != NULL){
            if(curr == dp){
                sum += root->val;
            }
        }
        
        findSum(root->left , curr+1 , dp);
        findSum(root->right ,curr+1 , dp);
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
        
        int dp = maxDepth(root) ;
         findSum(root,1,dp);
        
        return sum ;
    }
};