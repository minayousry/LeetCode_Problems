/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> dict;

    void parseNodes(Node* node)
    {

        if(node == nullptr || dict.find(node) != dict.end())
        {
            return;
        }
        else
        {
            dict[node] = new Node(node->val);
        }

        
        for(auto neighbour:node->neighbors)
        {
            parseNodes(neighbour);
        }
    }

    void clone(Node* node)
    {
        if(node->neighbors.size() ==  dict[node]->neighbors.size())
        {
            return;
        }
        else
        {
            
            for(int i=0;i<node->neighbors.size();++i)
            {
                dict[node]->neighbors.push_back(dict[node->neighbors[i]]);
            }
        }

        for(auto neighbour:node->neighbors)
        {
            clone(neighbour);
        }
    }





    Node* cloneGraph(Node* node) {
        
        if(node)
        {
            parseNodes(node);
            clone(node);
            return dict[node];
        }
        else
        {
            return nullptr;
        }
        
    }
};