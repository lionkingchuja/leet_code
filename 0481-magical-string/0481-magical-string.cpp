class Solution {
public:
    int magicalString(int n) {
        string s="122";
        int index=2;
        while(s.size()<n ){
            int repeat=s[index]-'0';
            char next=s.back() ^ 3;
            s +=string(repeat,next);
            index++;
        }
        // int cnt=0;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='1') cnt++;
        // }
    return count(s.begin(),s.begin()+n,'1');
    //return cnt;
    }
};