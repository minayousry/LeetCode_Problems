struct Node
{
    map<char,Node*> children;
    bool end_of_w;

    Node()
    {
        end_of_w = false;
    }


};

class Trie {
public:

    Node root;
    Trie() {
        
    }
    
    void insert(string word) {
        Node* current = &root;

        for(auto c:word)
        {
            if(current->children.find(c) == current->children.end())
            {
                current->children[c] = new Node;    
            }
            current = current->children[c];
            


        }
        current->end_of_w = true;
    }
    
    bool search(string word) {
        Node* current = &root;
        bool result = true;

        for(auto c:word)
        {
            if(current->children.find(c) != current->children.end())
            {
                current = current->children[c];
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
        Node* current = &root;
        bool result = true;

        for(auto c:prefix)
        {
            if(current->children.find(c) != current->children.end())
            {
                current = current->children[c];
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