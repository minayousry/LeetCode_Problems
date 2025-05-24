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

    unordered_map<int,int> inordere_index;
    int current_index;

    TreeNode* constructTree(vector<int>& preorder,int start_index,int end_index)
    {
        if(start_index > end_index)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[current_index]);

        int mid = inordere_index[preorder[current_index]];

        current_index++;

        root->left = constructTree(preorder,start_index,mid - 1);
        root->right = constructTree(preorder,mid + 1,end_index);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        current_index = 0;

        for(int i=0;i<inorder.size();++i)
        {
            inordere_index[inorder[i]] = i;
        }

        TreeNode *root;

        root = constructTree(preorder,0,preorder.size() - 1);
        return root;
        

    }
};