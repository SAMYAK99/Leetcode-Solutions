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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // If both trees are empty
        if(p == NULL and q == NULL)
            return true ; 
        
        // If one tree is empty and other tree is non empty
         if(p == NULL || q == NULL)
            return false ; 
        
        // If Current root value of First tree is != Second tree
         if(p->val != q->val)
             return false ; 
        
        // Recursive case : Both left subTree and right subTree must be equal
         return isSameTree(p->left,q->left) && isSameTree(p->right,q->right) ; 
    }
};