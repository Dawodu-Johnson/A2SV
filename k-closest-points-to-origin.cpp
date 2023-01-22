class Solution {
public:
    double distance(int x, int y){
        int answer=0;
        answer= pow(x-0,2);
        answer+=pow(y-0,2);
        double answer1= sqrt(answer);
        return answer1;
        
    }
    // 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<double, pair<int,int>> store;
        
        for(const auto&x: points){
           double temp= distance(x[0],x[1]);
          //  store[temp]= {x[0],x[1]};
            store.insert({temp, {x[0],x[1]}});
        }
        
        vector<vector<int>>store1;
        int counter=1;
        for(const auto&x: store){
            
            if(counter <=k){
            vector<int>temp(2);
            temp[0]= x.second.first;
            temp[1]=x.second.second;
            store1.push_back(temp);
                ++counter;
            }
            
            else break;
        }
        return store1;
    }
};
