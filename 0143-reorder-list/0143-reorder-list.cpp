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

        stack<ListNode*> nodes;
        ListNode result(0);
        ListNode* result_head = &result;


        ListNode* loop = head;

        while(loop)
        {
            nodes.push(loop);
            loop = loop->next;
        }
        
        int no_nodes = nodes.size();

        if(no_nodes<=2)
        {
            return;
        }

        loop = head;
        int count = 0;

        loop = head;

        while(count < no_nodes)
        {
            result_head->next = loop;
            loop = loop->next;
            result_head = result_head->next;

            count++;

            if(count >= no_nodes)
            {
                break;
            }

            result_head->next = nodes.top();
            nodes.pop();
            result_head = result_head->next;
            count++;
            

        }

        result_head->next = nullptr;
        
    }
};