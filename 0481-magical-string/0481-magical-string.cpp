class Solution {
public:
    int magicalString(int n) {
        int index=2;
        string s="122";
        int k=2;
        while(s.length() <n){
            int a=s[index]-'0';
            char x=('3'-s[k])+'0';
            while(a>0){
                k++;
                s.push_back(x);
                a--;
            }
            index++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ans++;
        }
        return ans;
    }
};