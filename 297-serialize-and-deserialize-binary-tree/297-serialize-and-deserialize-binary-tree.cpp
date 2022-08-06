/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    /*
     2 functions serialize and buildString for serialization :
     while building string we are doing pre order traversal and returned the built string.
     2 functions deserialize and buildTree for deserialization :
     From the string we were given, we seperated the individual nodes and 
     pushed them into a queue of string and with that queue we went into buildTree              function. There we took one string at a time from 
     the queue and constructed a TreeNode and keep on building the tree recursively
     and finally returned the root node.stoi() is a function to convert string to int
    */

    // Encodes a tree to a single string.
     void buildString(TreeNode* root, string &res)
    {
        if(root == NULL)
        {   res += "null,";
            return;
        }
        
        res += to_string(root->val) + ",";
        buildString(root->left, res);
        buildString(root->right, res);
    }
    
    string serialize(TreeNode* root) 
    { 
        string res = "";
        buildString(root, res);
        return res;
    }
    
    // Build Tree from Pre Order
    TreeNode* buildTree(queue<string> &q) 
    {
        string s = q.front();
        q.pop();
        
        if(s == "null")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(q);
        root->right = buildTree(q);
        return root;
    }
    
    //  Deserialziation
    TreeNode* deserialize(string data) 
    {
        string s = "";
        queue <string> q;
        
        for(char c: data) 
        {
            if(c == ',') 
            {
                q.push(s);
                s = "";
            }
            else
                s += c;
        }
        
        return buildTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));