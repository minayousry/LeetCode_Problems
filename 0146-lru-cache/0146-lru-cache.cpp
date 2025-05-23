struct Node
{
    struct Node* prev;
    struct Node* next;
    int m_key;
    int m_val;

    Node(int key,int val)
    {
        m_key = key;
        m_val = val;
        prev = nullptr;
        next = nullptr;
    }
    
};

class LRUCache {
public:
    int count;
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
        count = 0;
        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }

    void removefromRight(Node* current_node)
    {
        if(current_node)
        {
            current_node->prev->next = current_node->next;
            current_node->next->prev = current_node->prev;
        }
        else
        {
            cout<<"null ptr found in removefromRight"<<endl;
        }
    }

    void AddToLeft(Node* current_node)
    {
        if(current_node)
        {
            head->next->prev = current_node;
            current_node->next = head->next;
            current_node->prev = head;
            head->next = current_node;
        }
        else
        {
            cout<<"null ptr found in AddToLeft"<<endl;
        }
    }

    void moveNodeFromRightToLeft(Node* current_node)
    {
        removefromRight(current_node);
        AddToLeft(current_node);
    }
    
    int get(int key) {
        int found = -1;
        if(cache.find(key) != cache.end())
        {
            Node* found_node = cache[key];
            if(found_node != nullptr)
            {
                found = found_node->m_val;
                moveNodeFromRightToLeft(found_node);
            }
            else
            {
                cout<<"issue with key "<<key;
            } 
        }
        return found;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            Node* found_node = cache[key];
            found_node->m_val = value;
            moveNodeFromRightToLeft(found_node); 
        }
        else
        {
            if(count >= capacity)
            {
                Node* node_to_delete = tail->prev;
                removefromRight(node_to_delete);
                cache.erase(node_to_delete->m_key);
                delete node_to_delete;
                count--;
            }

            Node* new_node = new Node(key,value);
            AddToLeft(new_node);
            cache[key] = new_node;
            count++;


        }
        
    }
};