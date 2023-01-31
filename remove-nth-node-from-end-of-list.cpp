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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        ListNode* transverse= head;
        
        if(head==nullptr)return head;
        
        while(transverse!=nullptr){
              transverse= transverse->next;
              length+=1;
        }
        // given this we have the length already.
        
        if(length==1){
            delete head;
            return nullptr;
        }
        else if(length==n){
            // it means we are deleting the first node.
            ListNode* del=head;
            head=head->next;
            delete del;
            return head;
        }
        else{
            transverse=head;
            
            
            for(int i=1; i<(length-n); i++){
                transverse=transverse->next;
            }
            ListNode* del= transverse->next;
            transverse->next= del->next;
            delete del;
        }
        return head;
    }
};
