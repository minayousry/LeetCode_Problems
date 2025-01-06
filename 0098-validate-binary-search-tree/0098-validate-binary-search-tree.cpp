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
    bool dfs(TreeNode* node,long lower,long upper)
    {
        
        if(node == nullptr)
        {
            return true;
        }
        else
        {
            if((node->val <= lower) || (node->val >= upper))
            {
                return false;  
            }
            return dfs(node->left,lower,node->val)&&dfs(node->right,node->val,upper); 

        } 
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MIN,LONG_MAX);
    }
};