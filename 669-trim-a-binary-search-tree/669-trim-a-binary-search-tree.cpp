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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        //Base case
        if(root == NULL) {
            return NULL;
        }
        
        // iF VALUE IS IN RANGE
        if(root->val >= low && root->val <= high) {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
        
        // Ignore
        else if(root->val > high) {
            return trimBST(root->left, low, high);
        }
        
        // Ignore
        else if(root->val < low) {
            return trimBST(root->right, low, high);
        }
        
        return root;
        
    }
};