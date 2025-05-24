struct Node
{
    unordered_map<char ,unique_ptr<Node>> letters;
    bool is_end = false;
    Node()
    {
        is_end = false;
    }
};

class WordDictionary {
public:

    Node node;
    unique_ptr<Node> dictionary;

    WordDictionary() {
        dictionary = make_unique<Node>();
    }
    
    void addWord(string word) {
        
        int index = 0;
        Node* curr = dictionary.get();
        char letter;

        while(index < word.size())
        {
            letter = word[index];

            if(curr->letters.find(letter) == curr->letters.end())
            {
                curr->letters[letter] = std::make_unique<Node>();
            }

            curr = curr->letters[letter].get();
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
                curr = curr->letters[letter].get();
                index++;
            }
            else
            {
                for(auto &elm:curr->letters)
                {
                    if( check_word(elm.second.get(),word,index + 1) ) 
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
        return check_word(dictionary.get(),word,0);
    }
        
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */