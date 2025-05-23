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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* current = head;
        int total_nodes = 0;
        

        while(current)
        {
            total_nodes+= 1;
            current = current->next;
        }

        if(total_nodes <= 1)
        {
            head = nullptr;
        }
        else if(total_nodes == n)
        {
            cout<<"hiii";
            current = head;
            head = head->next;
            delete current;
        }
        else
        {
            current = head;

            int nodes_counter = 0;

            int node_index = total_nodes - n - 1;

            while(current != nullptr && nodes_counter < node_index)
            {
                current = current->next;
                nodes_counter++;
            }

            ListNode* deleted_node = current->next;

            current->next = deleted_node->next;
            delete deleted_node;

        }
        return head;

    }
};