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
    
    bool IsSameTree(TreeNode* tree1,TreeNode* tree2)
    {
        if(tree1 == tree2)
        {
             return true;
        }
        else if((tree1 == nullptr) || (tree2 == nullptr))
        {
            return false;
        }
        else if(tree1->val != tree2->val)
        {
            return false;
        }
        else
        {
            return (IsSameTree(tree1->left,tree2->left) && IsSameTree(tree1->right,tree2->right));
        }
            
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        queue<TreeNode*> elements;
        bool is_subtree = false;
        
        if((root == nullptr) || (subRoot == nullptr))
        {
            is_subtree =  false;
        }
        else
        {
            
            elements.push(root);
            TreeNode* element;
            bool left_leaf,right_leaf;
            
            while(!elements.empty())
            {
                element = elements.front();
                elements.pop();
                

                is_subtree |= IsSameTree(element,subRoot);
                
                if(is_subtree)
                {
                    break;
                }
                
                if(element->left)
                {
                    elements.push(element->left);
                }

                if(element->right)
                {
                    elements.push(element->right);
                }                


            }
            
        }
        return is_subtree;
    }
};