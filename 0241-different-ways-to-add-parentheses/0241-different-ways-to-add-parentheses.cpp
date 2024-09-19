class Solution {
public:
    vector<int> solve(string s){
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' or s[i]=='-' or s[i]=='*'){
                vector<int> ans1=solve(s.substr(0,i));
                vector<int> ans2=solve(s.substr(i+1));
                for(auto j:ans1){
                    for(auto k:ans2){
                        if(s[i]=='+') ans.push_back(j+k);
                        else if(s[i]=='-') ans.push_back(j-k);
                        else ans.push_back(j*k);
                    }
                }
            }
        }
        if(ans.size()==0) ans.push_back(stoi(s));
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};