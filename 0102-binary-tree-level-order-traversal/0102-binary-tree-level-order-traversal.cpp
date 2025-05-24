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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> data;

        vector<vector<int>> res;

        if(root)
            data.push(root);

        while(!data.empty())
        {
            int data_size = data.size();
            vector<int> line_data;

            for(int i=0;i<data_size;++i)
            {
                auto elm = data.front();
                data.pop();

                line_data.emplace_back(elm->val);

                if(elm->left)
                {
                    data.push(elm->left);
                }

                if(elm->right)
                {
                    data.push(elm->right);
                }
            }
            res.emplace_back(line_data);
        }

        return res;
    }
};