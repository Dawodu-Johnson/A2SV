class TopVotedCandidate {
public:
    vector<int>_persons;
    vector<int>_times;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        
        _persons.resize(persons.size());
        _persons[0] = persons[0];
        int answer = persons[0];
        int leading = 1;
        
        unordered_map<int, int>store;
        store[persons[0]]++;
        
        for(int i = 1; i < persons.size(); i++){
               store[persons[i]]++;
            
               if(store[persons[i]] >= leading){
                    _persons[i] = (persons[i]);
                    leading = store[persons[i]];
                    answer = persons[i];
               }
               else{
                    _persons[i] = (answer);
               }
        }
        
        _times = times;
    }
    
    int q(int t) {
        
        int l = prev(upper_bound(_times.begin(), _times.end(), t))-_times.begin();
        return _persons[l];
       
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
