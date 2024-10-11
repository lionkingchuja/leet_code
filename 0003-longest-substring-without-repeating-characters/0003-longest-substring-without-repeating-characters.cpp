class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int i=0;
        int j=0;
        int ans=0;
        while(j <s.size()){
            m[s[j]]++;
            if(m[s[j]]==1) ans=max(ans,j-i+1);
            else{
                while(m[s[j]] >1){
                    m[s[i]]--;
                    if(m[s[i]]==0) m.erase(s[i]);
                    i++;
                }
                if(m[s[j]]==1) ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};