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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode head;
        ListNode* tail = &head;

        int no_lists = lists.size();


        map<int,stack<ListNode*>> dict;

        for(int i=0;i<no_lists;++i)
        {
            while(lists[i] != nullptr)
            {
                dict[lists[i]->val].push(lists[i]);
                lists[i] = lists[i]->next;
            }
        }
    
        for(auto &elm:dict)
        {
            while(!elm.second.empty())
            {
                ListNode* temp = elm.second.top();
                elm.second.pop();
                tail->next = temp;
                tail = tail->next;
            }
        }

        // Ensure the last node points to nullptr
        tail->next = nullptr;
            

        return head.next;
        


        
    }
};