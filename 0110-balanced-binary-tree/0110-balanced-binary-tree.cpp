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

    pair<bool,int> checkbalanced(TreeNode* root)
    {
        bool result;
        if(!root)
        {
            return {true,0};
        }
        else
        {
            auto left = checkbalanced(root->left);
            auto right = checkbalanced(root->right);

            int diff = abs(left.second - right.second);
            result = left.first && right.first && (diff < 2);
            return {result,1 + max(left.second,right.second)};
        }
    }

    bool isBalanced(TreeNode* root) {
        return checkbalanced(root).first;
;    }
};