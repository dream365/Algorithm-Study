/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> elements;
        
        //1. current node point head node
        ListNode* cur = head;
        
        while(cur != NULL) {
        //2. if next node has same value with current node
        //   change next node to other node having another value with current node
            while(cur->next != NULL && cur->next->val == cur->val)
                cur->next = cur->next->next;
            
        //3. advance the current node to the next node
            cur = cur->next;
        }
        
        return head;
    }
};
