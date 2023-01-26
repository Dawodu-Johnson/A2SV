// we should probably use a linked list.. 
// should be fun actually

struct doublyLinkedList{
    
    int val;
    doublyLinkedList *prev, *next;
    
    doublyLinkedList(int value = -1): prev(nullptr), next(nullptr), val(value) {}
    
};

class MyCircularDeque {
    
    int size;
    int limits;
    doublyLinkedList*forward, *backward;
    
public:
    MyCircularDeque(int k) {
        
        size = 0;
        limits= k;
        forward =  nullptr;
        backward = nullptr;
        
    }
    
    bool insertFront(int value) {
        
        if(size==limits)return false;
        
        else if(forward==nullptr || backward==nullptr){
             forward = new doublyLinkedList(value);
             backward = forward;
        }
        
        else{
        doublyLinkedList* head = new doublyLinkedList(value);
        head->next=forward;
        forward->prev = head;
        forward = head; // update
        }
        size++;
        
        return true;
    }
    
    bool insertLast(int value) {
        if(size ==limits)return false;
        
        else if(forward==nullptr || backward==nullptr){
            backward = new doublyLinkedList(value);
            forward = backward;
        }
        else{
            
        doublyLinkedList* tail = new doublyLinkedList(value);
        
        backward->next = tail;
        tail->prev= backward;
        
        backward = tail; // update
        }
        size++;
        return true;
    }
    
    bool deleteFront() {
         if(forward==nullptr)return false;
        
         doublyLinkedList *temp = forward->next;
        
         delete forward;
        
         if(temp!=nullptr)temp->prev=nullptr;
        
         else {
              backward = nullptr;
         }
        
         forward = temp;
         size--;
        
         return true;
         
    }
    
    bool deleteLast() {
        if(forward==nullptr)return false;
        
        doublyLinkedList* temp = backward->prev;
        delete backward;
        
        if(temp!=nullptr){
             temp->next = nullptr;
        }
        
        else forward = nullptr;
        backward = temp;
        
        size--;
        return true;
    }
    
    
    int getFront() {
        
        if(forward==nullptr){
             return -1;
        }
        else return forward->val;
    }
    
    int getRear() {
        
        if(forward==nullptr){
             return -1;
        }
        return backward->val;
        
    }
    
    bool isEmpty() {
        return forward==nullptr;
    }
    
    bool isFull() {
        return size==limits;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
