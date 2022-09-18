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
    -> We are storing the next level of values and assigning it 
    -> to current node on current iterartion 
    */
    
    TreeNode* reverseOddLevels(TreeNode* root) {
    
         if(!root)
             return root; 
        
        queue<TreeNode*> q;
        vector<int> value;
        int level = 0 ;
        
        q.push(root);
        
        while(!q.empty()){
            vector<int> tmp ;
            int sz = q.size();
           
            for(int i=0 ; i<sz ; i++){
                
                TreeNode* node = q.front();
                q.pop();
                
                if(level % 2 != 0)
                    node->val = value[sz-i-1];
                
                if(node->left){
                    tmp.push_back(node->left->val);
                    q.push(node->left);
                }
                
                if(node->right){
                    tmp.push_back(node->right->val);
                    q.push(node->right);
                }
            }
            
            level++;
            value = tmp ;
        }
        
        return root ;
        
    }
};