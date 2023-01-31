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
    ListNode* middleNode(ListNode* head) {
        
        int length=0;
        
        ListNode* transverse=head;
        
        
        while(transverse!=nullptr){
            
            transverse=transverse->next;
            length+=1;
            
        }
        
        int middle=length/2;
        
        transverse=head;
        length=0;
        
        while(transverse!=nullptr){
            if(length==middle)return transverse;
            transverse=transverse->next;
            ++length;
        }
        
        return nullptr;
    }
};
