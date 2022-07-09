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
    
    int DFS(TreeNode* root,unordered_map<TreeNode *,int> &dict)
    {
        if(root == nullptr)
        {
            return 0;
        }
        else if( dict.find(root) != dict.end())
        {
            return dict[root];
        }
        
        int left_height = DFS(root->left,dict);
        int right_height = DFS(root->right,dict);
        
        dict[root] = max(left_height,right_height) + 1;
            
        return dict[root] ;
        

    }
    
    bool isBalanced(TreeNode* root)
    {
        unordered_map<TreeNode *,int> dict;

        bool is_balanced = true;

        queue<TreeNode *> elements;
        
        elements.push(root);
        TreeNode *element;
        int counter_right;
        int counter_left;
        
        while(!elements.empty())
        {
            counter_right = 0;
            counter_left = 0;
            
            element = elements.front();
            elements.pop();
            
            if(element != nullptr)
            {
                counter_left = DFS(element->left,dict);
                counter_right = DFS(element->right,dict);
                
                elements.push(element->left);
                elements.push(element->right);
                
            }
            
            int height = abs(counter_left - counter_right);


            if(height > 1)
            {
                is_balanced = false;
                break;
            }
        }        
        return is_balanced;
    }
};