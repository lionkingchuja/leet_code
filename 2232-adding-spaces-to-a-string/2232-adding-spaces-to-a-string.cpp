class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j=0;
        string ans="";
        for(int i=0;i< s.size();i++){
            if(i !=spaces[j]){
                ans +=s[i];
            }
            else{
                ans +=' ';
                ans +=s[i];
                if(j <spaces.size()-1) j++;
            }
        }
        return ans;
    }
};