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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node = headA;
        while(node->next != nullptr) {
            node = node->next;
        }
        node -> next = headA;
        ListNode* slow=headB;
        ListNode* fast=headB;
        bool intersection = false;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                intersection = true;
                break;
            }
        }

        if(!intersection) return nullptr;
        slow = headB;
        while(slow != fast) {
            cout << slow->val <<" " <<fast->val<<endl;
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};