struct Node
{
    map<char,unique_ptr<Node>> children;
    bool end_of_w;

    Node()
    {
        end_of_w = false;
    }


};

class Trie {
public:

    unique_ptr<Node> root;
    Trie() {
        root = make_unique<Node>();
    }
    
    void insert(string word) {
        Node* current = root.get();

        for(auto c:word)
        {
            if(current->children.find(c) == current->children.end())
            {
                current->children[c] = make_unique<Node>();    
            }
            current = current->children[c].get();
            


        }
        current->end_of_w = true;
    }
    
    bool search(string word) {
        Node* current = root.get();
        bool result = true;

        for(auto c:word)
        {
            if(current->children.find(c) != current->children.end())
            {
                current = current->children[c].get();
            }
            else
            {
                result = false;
                break;
            }
        }

        return (result && current->end_of_w);



    }
    
    bool startsWith(string prefix) {
        Node* current = root.get();
        bool result = true;

        for(auto c:prefix)
        {
            if(current->children.find(c) != current->children.end())
            {
                current = current->children[c].get();
            }
            else
            {
                result = false;
                break;
            }
        }

        return result;
            
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */