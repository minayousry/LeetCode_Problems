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

    int Dfs(TreeNode* root,int prev_val)
    {
        int result = 0;
        if(root != nullptr)
        {
            if(root->val >= prev_val)
            {
                result = 1;
            }
            prev_val = max(prev_val,root->val);
            result+= Dfs(root->left,prev_val);
            result+= Dfs(root->right,prev_val);  
        }
        return result;
    }
    int goodNodes(TreeNode* root) {

        int count = 0;
        int prev_val = INT_MIN;
        count = Dfs(root,prev_val);

        return count;
    }
};