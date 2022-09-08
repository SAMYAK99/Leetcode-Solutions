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
     vector<int> inorder ; 
    vector<int> inorderTraversal(TreeNode* root) {
        
          
         if(root==NULL)
           return inorder;
        
        // LNR
        
        if(root->left)
            inorderTraversal(root->left);
        if(root)
            inorder.push_back(root->val);
        if(root->right)
            inorderTraversal(root->right);
        
        return inorder;
    }
};