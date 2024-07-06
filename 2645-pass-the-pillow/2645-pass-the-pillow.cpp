class Solution {
public:
    int passThePillow(int n, int time) {
        vector<int>v;
        while(v.size() <=1000){
            int temp=n-1;
            int i=1;
            while(temp--){
                v.push_back(i);
                i++;
            }
            while(i>1){
                v.push_back(i);
                i--;
            }
        }
        // for(auto i:v) cout<<i<<" ";
        return v[time];
    }
};