/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> node_list;

        while(head)
        {
            node_list.emplace_back(head);
            head = head->next;
        }

        int half_nlist_size = node_list.size()/2;   
        int last_index = node_list.size() - 1;  

        for(int i=0;i < half_nlist_size;++i)
        {
            node_list[i]->next = node_list[last_index - i];
            node_list[last_index - i]->next = node_list[i + 1];
        }
        node_list[half_nlist_size]->next = nullptr;

        head = node_list[0];
    }
};