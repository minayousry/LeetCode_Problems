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

        ListNode result(0);

        ListNode* tail = &result;

        int remaining = 0;
        int eval = 0;

        while(l1 || l2)
        {
            if(l1 && l2)
            {
                eval = l1->val + l2->val;
            }
            else if(l1)
            {
                if(remaining == 0)
                {   
                    tail->next = l1;
                    break;
                }
                else
                {
                    eval = l1->val + remaining;
                    remaining = 0;
                }
                
            }
            else if(l2)
            {
                if(remaining == 0)
                {   
                    tail->next = l2;
                    break;
                }
                else
                {
                    eval = l2->val + remaining;
                    remaining = 0;
                }
            }
            else
            {
                break;
            }
            

            tail->next = new ListNode((eval + remaining)%10);

            remaining  = (eval + remaining)/10;

            

            if(l1)
                l1 = l1->next;
            if(l2)    
                l2 = l2->next;

            tail = tail->next;
        }

        if(remaining > 0)
        {
            tail->next = new ListNode(remaining);   
        }

        
        return result.next;
    }
};