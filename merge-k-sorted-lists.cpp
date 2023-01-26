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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr, *transverse=nullptr;
        priority_queue<int, vector<int>, greater<int> > data;
        
        for(int i = 0; i < lists.size(); i++){
                ListNode* transverse = lists[i];
                
                while(transverse!=nullptr){
                       data.push(transverse->val);
                       transverse = transverse->next;
                }
            
        }
        
        if(!data.empty()){
            head = new ListNode(data.top());
            transverse = head;
            data.pop();
        }
         
        while(!data.empty()){
        
                ListNode* create = new ListNode(data.top());
                transverse->next = create;
                transverse = transverse->next;
                data.pop();
         }
        
        return head;
        
    }
};
