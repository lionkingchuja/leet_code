class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>m;
        vector<pair<int,char>>vp;
        for(auto i:word) m[i]++;
        for(auto i:m) vp.push_back({i.second,i.first});
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());

        m.clear();
        int j=2;
        for(auto i:vp){
            if(j <=9) m[i.second]=1;
            else if(j <=17) m[i.second]=2;
            else if(j <=25) m[i.second]=3;
            else m[i.second]=4;
            j++;
        }
        int ans=0;
        for(auto i:word) ans +=m[i];
        return ans;
    }
};