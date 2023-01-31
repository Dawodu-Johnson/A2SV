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
    void deleteNode(ListNode* node) {
        // the only way to do it is to copy the details of the next node into his own.
        ListNode* d= node->next;
        *node= *d;   // everything about node is now === d.
        delete d;
    }
};
