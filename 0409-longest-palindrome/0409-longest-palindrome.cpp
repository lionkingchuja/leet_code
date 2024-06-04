class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        for(auto i:s) m[i]++;
        int ans=0;
        int cnt=0;
        for(auto i:m){
            if(i.second %2==0) ans +=i.second;
            else {
                cnt++;
                ans +=i.second-1;
            }
        }
        if(cnt>=1) return ans+1;
        else return ans;
    }
};