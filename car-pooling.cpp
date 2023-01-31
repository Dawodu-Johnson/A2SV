class Solution {
  
public:
    
      struct sortit{
        
         bool operator () (const vector<int>&f, const vector<int>&s){
               return f[2] >= s[2];
         }
    };
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        sort(trips.begin(),trips.end(),
              [](const vector<int>&x, const vector<int>&y){
              //return x[1] < y[1];
                  if(x[1] <y[1])return true;
                  else return false;
        });
        
        priority_queue<vector<int>,vector<vector<int>>, sortit>store;
        int size= trips.size(),total=0;
        // for(const auto&x: trips)store.push(x);
        // while(!store.empty()){
        //      vector<int>temp=store.top();
        //     for(const int &x: temp)cout << x << " ";
        //      cout << endl;
        //     store.pop();
        // }
        
        for(int i=0; i< size; i++){
            
            if(trips[i][0] >capacity)return false;
            
            else if(store.empty()){
                 store.push(trips[i]); 
                 total+=trips[i][0];
            }
            else if(trips[i][1] < store.top()[2]){
                 if(total+ trips[i][0] <=capacity){
                      store.push(trips[i]);
                      total+=trips[i][0];
                 }
                 else {return false;}
            }
            else {
                while(!store.empty() && trips[i][1] >=store.top()[2]){
                    total-=store.top()[0]; 
                    store.pop();
                }
             
                    if(store.empty()) {
                       store.push(trips[i]);
                       total+=trips[i][0];
                     }      
                     else if(total+ trips[i][0] <=capacity){
                        store.push(trips[i]);
                        total+=trips[i][0];
                     }
                 else return false;
            }

                
            }
        return true;
     
        
    }
};
