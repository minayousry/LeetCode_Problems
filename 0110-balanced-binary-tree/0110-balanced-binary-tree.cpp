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

    int dfs(TreeNode* root,bool &res)
    {
        if(root == nullptr)
        {
            return 0;
        }

        

        int lfs = dfs(root->left,res);
        int rfs = dfs(root->right,res);

        if(abs(lfs - rfs) > 1)
        {
            res &= false;
            return 0;
        }

        
        return 1 + max(lfs,rfs);
    }

    bool isBalanced(TreeNode* root) {

        bool result = true;

        
        dfs(root,result);

        return result;
        
    }
};