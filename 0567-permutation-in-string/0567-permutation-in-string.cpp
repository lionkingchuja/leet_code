class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int n=s1.size();
        int m=s2.size();
        vector<int>v1(27),v2(27);

        for(auto i:s1) v1[i-'a']++;
        for(int i=0;i<n-1;i++) v2[s2[i]-'a']++;

        int k=0;
        for(int i=n-1;i<m;i++){
            bool flag=true;
            v2[s2[i]-'a']++;
            for(int j=0;j<27;j++){
                if(v1[j] != v2[j]){
                    flag=false;
                    break;
                }
            }
            if(flag==true) return true;
            v2[s2[k]-'a']--;
            k++;
        }
        return false;
    }
};