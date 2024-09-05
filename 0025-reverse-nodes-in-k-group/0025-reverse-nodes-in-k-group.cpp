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
    // Helper function to reverse the first k nodes of the list starting at head
    ListNode* reverseList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next_ptr = nullptr;
        
        while (curr && k > 0) {
            next_ptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_ptr;
            k--;
        }
        
        // Connect the last node of the reversed part to the remaining list
        head->next = curr; // 'head' is now the last node after the reversal
        
        return prev; // Return new head after reversal
    }
    
    int countNodes(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        
        // Count the number of nodes in the list
        int no_nodes = countNodes(head);
        
        // If there are fewer than k nodes, return the list as is
        if (no_nodes < k) return head;
        
        // Reverse the first k nodes and get the new head
        ListNode* new_head = reverseList(head, k);
        ListNode* previous = head; // 'previous' is now the last node of the reversed group
        
        no_nodes -= k;
        
        while (no_nodes >= k) {
            ListNode* next_group_head = previous->next; // The start of the next group
            ListNode* new_group_head = reverseList(next_group_head, k);
            previous->next = new_group_head; // Connect the last node of the previous reversed group to the new head
            previous = next_group_head; // Move 'previous' to the last node of the new reversed group
            no_nodes -= k;
        }
        
        return new_head;
    }
};
