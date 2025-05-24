struct Node
{
    unordered_map<char ,Node*> letters;
    bool is_end = false;
    Node()
    {
        is_end = false;
    }
};

class WordDictionary {
public:

    Node node;
    Node* dictionary;

    WordDictionary() {
        dictionary = &node;
    }

    void freeNode(Node* root)
    {
        for(auto &elm:root->letters)
        {
            freeNode(elm.second);
            delete elm.second;
        }
    }

    ~WordDictionary()
    {
        for(auto &elm:dictionary->letters)
        {
            freeNode(elm.second);
        }
    }

    
    void addWord(string word) {
        
        int index = 0;
        Node* curr = dictionary;
        char letter;

        while(index < word.size())
        {
            letter = word[index];

            if(curr->letters.find(letter) == curr->letters.end())
            {
                curr->letters[letter] = new Node();
            }

            curr = curr->letters[letter];
            index++;
        }
        curr->is_end = true;
    }

    bool check_word(Node* dict,string &word,int index)
    {
        Node* curr = dict;
        char letter;

        while(index < word.size())
        {
            letter = word[index];

            if(letter != '.')
            {
                if(curr->letters.find(letter) == curr->letters.end())
                {
                    return false;
                }
                curr = curr->letters[letter];
                index++;
            }
            else
            {
                for(auto &elm:curr->letters)
                {
                    if( check_word(elm.second,word,index + 1) ) 
                    {
                        return true;
                    }
                }
                return false;
            }
        }

        return (curr->is_end);
    }
    
    bool search(string word) {
        return check_word(dictionary,word,0);
    }
        
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */