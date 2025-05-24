struct Node
{
    unordered_map<char,Node*> data;
    bool is_end;

    Node()
    {
        is_end = false; 
    }
    
};

class Trie {
public:
    Node dummy_node;
    Node* tree;

    Trie() {
        tree = &dummy_node;   
    }
    
    void insert(string word) {
        
        Node* current = tree;
        Node* prev = nullptr;
        int index = 0;

        while(current != nullptr && index < word.size())
        {
            if(current->data.find(word[index]) == current->data.end())
            {
                current->data[word[index]] = new Node(); 

            }
            prev = current;
            current = current->data[word[index]];
            index++;
        }
        current->is_end = true;
    }
    
    bool search(string word) {
        
        Node* current = tree;
        Node* prev = nullptr;
        int index = 0;

        while(current != nullptr && index < word.size())
        {
            if(current->data.find(word[index]) == current->data.end())
            {
                return false;                
            }
            prev = current;
            current = current->data[word[index]];
            index++;
        }

        return (current->is_end) && (index == word.size());
    }
    
    bool startsWith(string prefix) {
        Node* current = tree;
        int index = 0;

        while(current != nullptr && index < prefix.size())
        {
            if(current->data.find(prefix[index]) == current->data.end())
            {
                return false;                
            }

            current = current->data[prefix[index]];
            index++;
        }

        return (index == prefix.size());
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */