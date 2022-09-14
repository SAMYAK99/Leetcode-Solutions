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
    Brute Force : O(n^2)
    Fix a node and move towards all the node in the tree

    
    */
    
    long long total = 0 ; 
    
    int pathSum(TreeNode* root, int targetSum) {
        
        if(!root)
            return total;
        
        findPathSum(root,targetSum , 0);
        pathSum(root->left , targetSum);
        pathSum(root->right ,targetSum);
        
        return total ;
        
    }
    
    void findPathSum(TreeNode *root , int targetSum ,long long currentSum){
        
        if(!root)
            return ;
        
        currentSum += root->val ; 
        
        if(currentSum == targetSum)
            total++;
        
        findPathSum(root->left , targetSum , currentSum);
        findPathSum(root->right ,targetSum , currentSum) ;
        
    }
};