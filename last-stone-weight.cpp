class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>store_stones;
        
        for(int i = 0 ; i < stones.size(); i++){
             
               store_stones.push(stones[i]);
            
        }
        
        
        while(store_stones.size() >=2){
              int first  = store_stones.top();
              store_stones.pop(); 
              int second = store_stones.top();
              store_stones.pop();
              if(abs(first-second)!=0){
                   store_stones.push(abs(first-second));
              }
        }
        
        return store_stones.empty() ? 0 : store_stones.top();
    }
};
