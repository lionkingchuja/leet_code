class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        int cnt=0;
        int j=0;
        for(int i=0;i< goal.size();i++){
            if(goal[j] == s[i]){
                j++;
                cnt++;
            }
        } 
        if(cnt==s.size()) return true;
        for(int i=0;i< s.size();i++){
            if(s[i]==goal[j]){
                cout<<goal[j]<<" ";
                j++;
                cnt++;
                if(cnt==s.size()) return true;
            }
            else return false;
        }
        return false;
    }
};