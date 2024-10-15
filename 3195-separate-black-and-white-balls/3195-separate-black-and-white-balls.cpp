class Solution {
public:
    long long minimumSteps(string s) {
        int cnt1=0;
        for(auto i:s){
            if(i=='1') cnt1++;
        }
        vector<int>v1,v2;
        int j=s.size()-1;
        int len=cnt1;
        while(len--){
            if(s[j]=='0') v1.push_back(j);
            j--;
        }
        
        while(j>=0){
            if(s[j]=='1') v2.push_back(j);
            j--;
        }
        cout<<v1.size();
        cout<<v2.size();
        long long ans=0;
        for(int i=0;i< v1.size();i++){
            ans +=abs(v1[i]-v2[i]);
        }
        return ans;
    }
};