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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> data;
        vector<int> result;

        
        if(!root)
        {
            return result;
        }
        


        
        auto curr = root;

        while(curr || !data.empty())
        {
            while(curr)
            {
                data.push(curr);
                curr = curr->left;
            }

            curr = data.top();
            data.pop();

            result.push_back(curr->val);

            curr = curr->right;


        }

        return result;
    }
};