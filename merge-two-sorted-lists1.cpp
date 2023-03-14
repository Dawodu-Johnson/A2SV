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
    ListNode*head = nullptr, *head1=nullptr;
    
    void merge(ListNode* list1, ListNode* list2){
        
        ListNode* newNode = new ListNode();
        
        if(list1==nullptr && list2==nullptr)return;
        
        else if(list1!=nullptr && list2!=nullptr){
            
              if(list1->val <= list2->val){
                  newNode->val = list1->val;
                  list1 = list1->next;
              }
            
              else{
                  newNode->val = list2->val;
                  list2 = list2->next;
              }
            
              if(head1==nullptr){
                   head = newNode;
                   head1 = newNode;
              }
              else{
                   head->next = newNode;
                   head = head->next;
                  
              }
            
        }
        
      else if(list1!=nullptr){
          newNode->val = list1->val;
          if(head1==nullptr){
               head = newNode;
               head1 = newNode;
          }
          else{
               head->next = newNode;
               head = head->next;
          }
          
          list1 = list1->next;
      }
        
      else if(list2!=nullptr){
         
           newNode->val = list2->val;
            if(head1==nullptr){
                   head = newNode;
                   head1 = newNode;
            }
           else{
               head->next = newNode;
               head = head->next;
            }
          
          list2 = list2->next;
      }
        
      merge(list1, list2);
        
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        merge(list1, list2);
        return head1;
    }
};
