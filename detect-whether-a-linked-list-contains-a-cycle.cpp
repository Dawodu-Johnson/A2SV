

// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
unordered_map<SinglyLinkedListNode*,int>check;
SinglyLinkedListNode* temp=head; //  used for transversing.

while(temp!=nullptr){
    if(check[temp]++ > 0)return 1;
    temp=temp->next;
}
return 0;
}

