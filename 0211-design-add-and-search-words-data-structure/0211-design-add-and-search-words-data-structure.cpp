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

    ~Node()
    {
        for(int i=0;i<26;i++)
        {
            delete children[i];
        }
    }
};

class WordDictionary {
public:
    Node tree_root;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node* current = &tree_root;
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

    bool dfs(string &word,int start_index,Node* root)
    {
        Node* current = root;
        bool result = true;
        int index;

        for(int i=start_index;i<word.size();++i)
        {
            if(word[i] == '.')
            {   
                for(int j=0;j<26;++j)
                {
                    if((current->children[j] != nullptr) && dfs(word,i+1,current->children[j]))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                index = word[i] - 'a';

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
        }
        return (result && current->end_of_w);
    }
    
    bool search(string word) {
        return dfs(word,0,&tree_root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

