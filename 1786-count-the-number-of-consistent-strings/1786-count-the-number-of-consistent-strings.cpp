class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int>m;
        int cnt=0;
        for(int i=0;i< words.size();i++){
            for(auto i:allowed) m[i]++;
            string temp=words[i];
            bool flag=true;
            for(int j=0;j<temp.size();j++){
                if(m.find(temp[j]) != m.end()){
                    m[temp[j]]--;
                    flag=true;
                }
                else {
                    flag=false;
                    break;
                }
            }
            if(flag ==true) cnt++;
        }
        return cnt;
    }
};