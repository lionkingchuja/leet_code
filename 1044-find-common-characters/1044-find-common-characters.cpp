class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>min_freq(26,INT_MAX);
        for(auto& i:words){
            vector<int>freq(26,0);
            for(auto c:i){
                freq[c-'a']++;
            }
            for(int i=0;i< 26;i++){
               min_freq[i]=min(min_freq[i],freq[i]);
            }
        }
        vector<string>ans;
        for(int i=0;i<26;i++){
            while(min_freq[i]-- >0){
                ans.push_back(string(1,i+'a'));
            }
        }
        return ans;
    }
};