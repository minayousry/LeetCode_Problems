/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        Node head2(0);

        Node* temp_head = head;

        unordered_map<Node*,Node*> mapped_address;

        Node* tail = &head2;


        while(temp_head)
        {
            tail->next = new Node(temp_head->val);

            mapped_address[temp_head] = tail->next;
            
            temp_head = temp_head->next;
            tail = tail->next;

        }

        tail = &head2;
        temp_head = head;

        while(temp_head)
        {
            tail->next->random = mapped_address[temp_head->random];
            temp_head = temp_head->next;
            tail = tail->next;

        }

        
        return head2.next;
    }
};