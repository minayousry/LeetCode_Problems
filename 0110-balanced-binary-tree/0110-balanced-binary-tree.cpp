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
    pair<bool,int> isSubtreeBalanced(TreeNode* root)
    {
        if(root == nullptr)
        {
            return {true,0};
        }
        else
        {
            auto left_branch = isSubtreeBalanced(root->left);
            auto right_branch = isSubtreeBalanced(root->right);

            bool result = left_branch.first && right_branch.first && (abs(left_branch.second - right_branch.second) <= 1 );
            
            cout<<1 + max(left_branch.second,right_branch.second)<<endl;
            return {result,1 + max(left_branch.second,right_branch.second)};
            
        }
    }

    bool isBalanced(TreeNode* root) {
        if(root)
        {
            return isSubtreeBalanced(root).first;
        }
        return true;
    }
};