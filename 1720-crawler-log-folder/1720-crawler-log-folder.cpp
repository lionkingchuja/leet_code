class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<char>st;
        for(int i=0;i<logs.size();i++){
            if(!st.empty() and logs[i]=="../"){
                st.pop();
            }
            else if(logs[i]=="./") continue;
            else if(logs[i] !="../"){
                st.push('x');
            }
        }
        return st.size();
    }
};