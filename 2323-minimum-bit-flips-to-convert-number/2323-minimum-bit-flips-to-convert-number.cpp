class Solution {
public:
    int minBitFlips(int start, int goal) {
        string s="";
        string e="";
        while(start >0){
            s.push_back((start % 2)+'0');
            start /=2;
        }

        while(goal >0){
            e.push_back((goal % 2)+'0');
            goal /=2;
        }
        while(s.size() > e.size()){
            e.push_back('0');
        }
        while(e.size() > s.size()){
            s.push_back('0');
        }
        reverse(s.begin(),s.end());
        reverse(e.begin(),e.end());
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=e[i]) ans++;
        }
        return ans;
    }
};