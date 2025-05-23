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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode dummy_node;
        ListNode* result_list = &dummy_node;


        int rem = 0;
        int sum = 0;
        int res;

        while(l1 && l2)
        {
            
            sum = (l1->val + l2->val + rem);
            res = sum % 10;
            rem = sum / 10;

            result_list->next = new ListNode(res);

            l1 = l1->next;
            l2 = l2->next;
            result_list = result_list->next;
        }

        while(l1)
        {
            sum = l1->val + rem;
            res = sum % 10;
            rem = sum / 10;

            result_list->next = new ListNode(res);
            l1 = l1->next;
            result_list = result_list->next; 
        }

        while(l2)
        {
            sum = l2->val + rem;
            res = sum % 10;
            rem = sum / 10;

            result_list->next = new ListNode(res);
            l2 = l2->next;
            result_list = result_list->next; 
        }

        if(rem > 0)
        {
            result_list->next = new ListNode(rem);
        }

        return dummy_node.next;
            
    }
    
};