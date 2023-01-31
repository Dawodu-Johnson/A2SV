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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
        
         
ListNode* head=nullptr;
    
    if(head1==nullptr && head2==nullptr)return head;
    
    else if(head1==nullptr)return head2;
    
    else if(head2==nullptr)return head1;
    
    else {
          
           if(head1->val <= head2->val){
               head= head1;
               head1=head1->next;
           }
           else {
               head=head2;
               head2=head2->next;
           }
           
           ListNode* transverse=head;
           
           while(head1!=nullptr && head2!=nullptr){
               
               if(head1->val < head2->val){
                   transverse->next=head1;
                   head1=head1->next;
               }
               else {
                   transverse->next= head2;
                   head2= head2->next;
               }
               
               transverse=transverse->next;
           }
           
        // it's a linked list already, so we don't need to while it.
           if(head1!=nullptr){
               transverse->next=head1;
               head1=head1->next;
           }
           
           if(head2!=nullptr){
               transverse->next=head2;
               head2=head2->next;
           }
           
        
         
           return head;
           
    }
}
    
};
