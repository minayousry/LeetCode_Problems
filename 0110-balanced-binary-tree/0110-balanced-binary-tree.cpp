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

    pair<bool,int>  getMaxHeight(TreeNode* root)
    {
        pair<bool,int> result;

        if(root == nullptr)
        {
            result.first = true;
            result.second = 0;
            return result;    
        }

        pair<bool,int> lhs = getMaxHeight(root->left);
        pair<bool,int> rhs = getMaxHeight(root->right);
        
        bool balanced = lhs.first && rhs.first && (abs(lhs.second - rhs.second) <= 1U);
        int height = 1 + max(lhs.second,rhs.second);

        result.first = balanced;
        result.second = height;

        return result;         

    }

    bool isBalanced(TreeNode* root) {

        return getMaxHeight(root).first;
        
    }
};