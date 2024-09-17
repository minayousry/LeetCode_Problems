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

    void Dfs(TreeNode* root,int prev_val,int &count)
    {
        
        if(root != nullptr)
        {
            if(root->val >= prev_val)
            {
                count++;
            }
            prev_val = max(prev_val,root->val);
            Dfs(root->left,prev_val,count);
            Dfs(root->right,prev_val,count);
            
        }
    }
    int goodNodes(TreeNode* root) {

        int count = 0;
        int prev_val = INT_MIN;
        Dfs(root,prev_val,count);

        return count;
    }
};