class Solution {
public:
    
   vector<vector<int>>data_base;

   void solve(int n,int value, int k,vector<int>&store){

       if((int)store.size()==k){
          data_base.push_back(store);
          return;
       }

       if(value >n)return;

       //vector<int>temp=store;   
                  // we are storing the temp for the exclude version.

       store.push_back(value);
       solve(n, value+1,k,store); // include
       store.pop_back();
       solve(n,value+1,k,store);         //exclude.

}

    vector<vector<int>> combine(int n, int k) {
        vector<int>store;
        solve(n,1,k,store);
        return data_base;
    }
};
