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


    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;

        stack<TreeNode*> data;

        if(root)
        {
            data.push(root);
        }

        while(!data.empty())
        {
            auto elm = data.top();
            data.pop();

            values.push_back(elm->val);

            if(elm->right)
            {
                data.push(elm->right);
            }

            if(elm->left)
            {
                data.push(elm->left);
            }


        }

        sort(values.begin(),values.end());

        return values[k - 1];

    }
};
