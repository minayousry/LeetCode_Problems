struct Node
{
    unordered_map<char,Node*> data;
    bool end;

    Node()
    {
        end = false;
    }
};


class WordDictionary {
public:
    Node* dict;

    WordDictionary() {
        dict = new Node();
    }
    
    void addWord(string word) {
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



    bool dfs(string &word,int index,Node* root)
    {
        bool result = true;
        Node* curr = root;

        int i = index;

        while(i < word.size())
        {
            if(curr->data.size() == 0)
            {
                return false;
            }
            else if( (word[i] != '.') && (curr->data.find(word[i]) == curr->data.end()) )
            {
                return false;
            }
            else if((word[i] != '.') && (curr->data.find(word[i]) != curr->data.end()))
            {
                curr = curr->data[word[i]];
                i++;
            }
            else
            {
                for(auto &pair:curr->data)
                {
                    if(dfs(word,i+1,pair.second))
                    {
                        return true;
                    }
                }
                return false;
            }

        }

        return  curr->end == true;
    }
    
    bool search(string word) {
        
        return dfs(word,0,dict);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */