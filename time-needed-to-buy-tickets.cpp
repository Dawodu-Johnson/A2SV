class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
          
        int size = tickets.size(), answer = 0;
        while(true){
             
               for(int i = 0; i < size; i++){
                   
                     if(tickets[i] >0){
                         tickets[i]-=1;
                         answer++;
                     }
                   
                    if(tickets[k]==0)return answer;
               }
        }
        
        return 0;  // this is not going to run
    }
};
