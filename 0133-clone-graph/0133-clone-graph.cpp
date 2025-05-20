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

    Node* cloneNode(Node* node)
    {
        Node* copy;
        if(node == nullptr)
        {
            return nullptr;
        }
        else if(dict.find(node) != dict.end())
        {
            return dict[node];
        }
        else
        {
            copy = new Node(node->val);
            dict[node] = copy;

            for(const auto &neighbour:node->neighbors)
            {
                copy->neighbors.emplace_back(cloneNode(neighbour));
            }
            
        }
        return copy;

    }

    Node* cloneGraph(Node* node) {
        return cloneNode(node);
    }
};