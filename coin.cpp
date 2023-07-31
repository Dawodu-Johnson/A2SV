class Solution {
public:
     int answer(vector<int>&coins, int amount, int siz,vector<vector<int>>&memoization){

       if(amount==0 || siz==-1 ){
          return (amount==0 ? 0: numeric_limits<int>::max()-1);
       }

       else if(memoization[siz][amount]!=-1)return memoization[siz][amount];

       else if(coins[siz]>amount) return memoization[siz][amount]=answer(coins, amount, siz-1,memoization);

        return memoization[siz][amount]=min(answer(coins, amount-coins[siz],siz,memoization)+1, answer(coins,amount,siz-1,memoization));
    }
    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>>memoization(coins.size(),vector<int>(amount+1,-1));
        int value= answer(coins, amount,coins.size()-1, memoization);
        if(value== numeric_limits<int>::max()-1)return -1;
        return value;
    }

   
};
