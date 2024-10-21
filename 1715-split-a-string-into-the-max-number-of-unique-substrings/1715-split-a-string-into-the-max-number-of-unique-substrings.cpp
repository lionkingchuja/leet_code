class Solution {
public:
    int max_count=0;
    void solve(int index,string &s,unordered_set<string>&st){
        if(index==s.size()){
            max_count=max(max_count,(int)st.size());
            return;
        }
        for(int i=index+1;i<=s.size();i++){
            string sub=s.substr(index,i-index);
            if(st.find(sub)==st.end()){
                st.insert(sub);
                solve(i,s,st);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        solve(0,s,st);
        return max_count;
    }
};