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

    int countNode(ListNode* head)
    {
        int count = 0;
        while(head)
        {
            head = head->next;
            count++;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int total = countNode(head);
        int count = 1;
        ListNode* start = head;

        if(n == total)
        {
            start = head->next;
        }
        else
        {
        
            while(count < (total - n))
            {
                head = head->next;
                count++;
            }
        
            if(total > 1)
            {
                ListNode* next_node = head->next->next;
                delete(head->next);
                head->next = next_node;
            }
        }
        

        return start;


        
    }
};