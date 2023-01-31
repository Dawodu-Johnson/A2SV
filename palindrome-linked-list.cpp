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
    bool isPalindrome(ListNode* head) {
      
        if(head==nullptr)return true;
        
        ListNode* transverse=head;
        
        ListNode* temp=nullptr;
        
        while(transverse!=nullptr){
            
            ListNode* create= new ListNode(transverse->val);
            create->next= temp;
            temp=create;
            
            transverse= transverse->next;
        
        }
        
        bool answer = true;
        
        while(temp!=nullptr && head!=nullptr){
            
            if(temp->val!=head->val){
                answer=false;
                break;
            }
            else {
                temp=temp->next;
                head=head->next;
            }
        
        }
        return answer;
    }
};
