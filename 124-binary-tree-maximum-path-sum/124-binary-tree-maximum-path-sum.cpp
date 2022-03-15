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
    int maxPathSum(TreeNode* root) {
        
        int sum = INT_MIN ;
        maxSum(root,sum);
        
        return sum ; 
    }
    
    
    
    int maxSum(TreeNode* root , int &sum){
        
        if(root == NULL)
            return  0 ;
        
        
        
    // Do not consider the negative path sum as it always gives lower value
        int leftSum = max(0,maxSum(root->left,sum));
        int rightSum = max(0,maxSum(root->right,sum));
        
        // Maximum sum of every path
        sum = max(sum , root->val + leftSum + rightSum) ; 
        
        //On every node which is the longest path is what we return 
        return max(leftSum , rightSum) + root->val ; 
    }
    
    
};