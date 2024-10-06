struct Node
{
    Node* children[26];
    bool end_of_w;

    Node()
    {
        for(int i=0;i<26;i++)
        {
            children[i] = nullptr;
        }
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
        int index;

        for(auto &c:word)
        {
            index = c - 'a';
            if(current->children[index] == nullptr)
            {
                current->children[index] = new Node;    
            }
            current = current->children[index];
            
        }
        current->end_of_w = true;
    }
    
    bool search(string word) {
        Node* current = &root;
        bool result = true;
        int index;

        for(auto &c:word)
        {
            index = c - 'a';
            if(current->children[index] != nullptr)
            {
                current = current->children[index];
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
        int index;

        for(auto &c:prefix)
        {
            index = c - 'a';
            if(current->children[index] != nullptr)
            {
                current = current->children[index];
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