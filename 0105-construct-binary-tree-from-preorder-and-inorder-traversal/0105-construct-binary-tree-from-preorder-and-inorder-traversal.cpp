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
    int counter = 0;

    TreeNode* buildsubtree(vector<int>& preorder,unordered_map<int,int> &mapping,int l,int r)
    {
        
        if( l > r)
        {
            return nullptr;
        }

        int root_val = preorder[counter];
        TreeNode* root = new TreeNode(root_val);
        counter++;
        
        int mid = mapping[root_val];
        

        root->left = buildsubtree(preorder,mapping,l,mid - 1);

        root->right = buildsubtree(preorder,mapping,mid + 1,r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int> mapping_data;

        for(int i=0;i<inorder.size();++i)
        {
            mapping_data[inorder[i]] = i;
        }  

        return buildsubtree(preorder,mapping_data,0,preorder.size() - 1);  
    }
    
};