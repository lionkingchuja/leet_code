class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        vector<int>v(27,0);int ma=0;
        while(j<s.length()){
            v[s[j]-'A']++;
            if(j-i+1-*max_element(v.begin(),v.end())>k){
                v[s[i]-'A']--;
                i++;
            }
            ma=max(ma,j-i+1);
            j++;
        }
    return ma;
    }
};