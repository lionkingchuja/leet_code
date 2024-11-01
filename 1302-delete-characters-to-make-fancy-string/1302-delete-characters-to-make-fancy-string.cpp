class Solution {
public:
    string makeFancyString(string s) {
        stack<char>st;
        for(int i=0;i< s.size();i++){
            if(!st.empty() and st.top()==s[i] and s[i]==s[i+1]) continue;
            else st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans +=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};