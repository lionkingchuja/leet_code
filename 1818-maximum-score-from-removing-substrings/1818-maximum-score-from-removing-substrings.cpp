class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char>st,st1;
        int ans1=0,ans2=0;
        if(x>=y){
            for(int i=0;i<s.size();i++){
                if(!st.empty() and st.top()=='a' and s[i]=='b'){
                    st.pop();
                    ans1 +=x;
                }
                else st.push(s[i]);
            }
            string temp="";
            while(!st.empty()){
                temp.push_back(st.top());
                st.pop();
            }
            reverse(temp.begin(),temp.end());
            for(int i=0;i< temp.size();i++){
                if(!st1.empty() and st1.top()=='b' and temp[i]=='a'){
                    st1.pop();
                    ans1 +=y;
                }
                else st1.push(temp[i]);
            }
        }
        else{
            for(int i=0;i<s.size();i++){
                if(!st.empty() and st.top()=='b' and s[i]=='a'){
                    st.pop();
                    ans1 +=y;
                }
                else st.push(s[i]);
            }
            string temp="";
            while(!st.empty()){
                temp.push_back(st.top());
                st.pop();
            }
            reverse(temp.begin(),temp.end());
            for(int i=0;i< temp.size();i++){
                if(!st1.empty() and st1.top()=='a' and temp[i]=='b'){
                    st1.pop();
                    ans1 +=x;
                }
                else st1.push(temp[i]);
            }
        }
        return ans1;
    }
};