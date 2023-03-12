class DataStream {
     deque<int>store;
     int value,k;
     int size;
public:
    DataStream(int value, int k) {
        this->value =value;
        this->k = k;
        size = 0;
    }
    
    bool consec(int num) {
   
        if(num == value){
             store.push_back(num);
            size++;
        }
        else{
             size = 0;
        
        }
        
        if(size ==k){
            size--;
            return true;
        }
        else{
             return false;
        }
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
