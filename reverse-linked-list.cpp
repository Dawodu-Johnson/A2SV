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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* transverse=head;
        ListNode* nextNode=nullptr;
        ListNode* previousNode=nullptr;
        
        
        while(transverse!=nullptr){
            
            nextNode= transverse->next;
            transverse->next=previousNode;
            previousNode=transverse;
            transverse=nextNode;
            
        }
        
        // x->y->z
        return previousNode;
        
    }
};
