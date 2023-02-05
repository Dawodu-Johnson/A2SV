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
    ListNode* deleteDuplicates(ListNode* head) {
        
        int value;
        if(head==nullptr)return head;
        ListNode* transverse= head,*prev=nullptr;
        
        while(transverse!=nullptr && transverse->next!=nullptr){
            
            if(transverse->val==transverse->next->val){
                   value= transverse->val;
                
                   while(transverse!=nullptr && transverse->val==value){
                       
                       if(prev==nullptr){
                           head= transverse->next;
                           delete transverse;
                           transverse= head;
                       }
                       else {
                           prev->next= transverse->next;
                           delete transverse;
                           transverse= prev->next;
                       }
                   }
            }
            
            else{
                prev= transverse;
                transverse=transverse->next;
            }
        }
        
        return  head;
        
    }
};
