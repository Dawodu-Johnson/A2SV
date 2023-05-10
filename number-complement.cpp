class Solution {
public:
    int findComplement(int num) {
        vector<int>store(32,0);
        int counter = 0;
        
        while(num){
            store[counter++] = !(num&1);
            num>>=1;
        }
        
        int answer = 0;
        for(int i = 0; i < store.size(); i++){
            answer+=(store[i]* (1 << i));
        }
        return answer;
    }
};
