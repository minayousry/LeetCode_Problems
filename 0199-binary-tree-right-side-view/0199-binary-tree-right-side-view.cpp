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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> data;

        vector<int> res;

        if(root)
            data.push(root);

        while(!data.empty())
        {
            int data_size = data.size();

            int last_elm = -1;

            for(int i=0;i<data_size;++i)
            {
                auto elm = data.front();
                data.pop();

                last_elm = elm->val;


                if(elm->left)
                {
                    data.push(elm->left);
                }

                if(elm->right)
                {
                    data.push(elm->right);
                    
                }
            }
            res.emplace_back(last_elm);
        }

        return res;
    }
};