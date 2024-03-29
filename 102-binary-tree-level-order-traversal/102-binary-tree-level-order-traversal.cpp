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
    -> Iterative method : Level order traversal without Recursion
    */
    
    vector<vector<int>> levelOrder(TreeNode* root) {
           vector<vector<int>> ans ; 
    
        if(root == NULL)
            return ans ; 
        
        queue<TreeNode*> q;
        q.push(root) ;
        
        while(!q.empty()){
            
            int currsize = q.size();                
			vector<int>level; 
            
              while(currsize > 0){
                  
                  auto t = q.front();
                  level.push_back(t->val);
                  currsize--;
                  q.pop();
            
                  if(t->left != NULL)
                    q.push(t->left);
                  if(t->right != NULL)
                    q.push(t->right) ;
                  
              }
            
            ans.push_back(level) ; 
            
        }
        
        return ans ; 
       
    }
};