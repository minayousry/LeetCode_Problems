struct Node
{
    unordered_map<char,Node*> data;
    bool end;

    Node()
    {
        end = false;
    }
};


class Trie {
public:
    Node* dict;
    Trie() {
        dict = new Node();
        
    }
    
    void insert(string word) {
        Node* curr = dict;

        for(int i=0;i<word.size();++i)
        {
            if(curr->data.find(word[i]) == curr->data.end())
            {
                curr->data[word[i]] = new Node();
            }
            curr = curr->data[word[i]];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        bool result = true;
        Node* curr = dict;

        int i = 0;

        while((i < word.size()) && (curr->data.find(word[i]) != curr->data.end()))
        {
            curr = curr->data[word[i]];
            i++;
        }

        result = (i == word.size()) && (curr->end == true);

        return result;
    }
    
    bool startsWith(string prefix) {
        bool result = true;
        Node* curr = dict;

        int i = 0;

        while((i < prefix.size()) && (curr->data.find(prefix[i]) != curr->data.end()))
        {
            curr = curr->data[prefix[i]];
            i++;
        }

        result = (i == prefix.size());

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