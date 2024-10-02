class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        set<int>s;
        for(auto i:arr) s.insert(i);

        unordered_map<int,int>store;
        int cnt=1;
        for(auto i:s){
            store[i]=cnt;
            cnt++;
        }
        vector<int>ans;
        for(auto i:arr){
            if(store.find(i) !=store.end()){
                ans.push_back(store[i]);
            }
        }
        return ans;
    }
};