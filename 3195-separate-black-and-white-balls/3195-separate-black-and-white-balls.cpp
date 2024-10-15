class Solution {
public:
    long long minimumSteps(string s) {
        int i=0;
        int j=s.size()-1;
        long long ans=0;
        bool flag1=false;
        bool flag2=false;
        while(i<j){
            if(s[i]=='0') i++;
            else flag1=true;
            if(s[j]=='1') j--;
            else flag2=true;
            if(flag1==true and flag2==true){
                ans +=j-i;
                flag1=false;
                flag2=false;
                i++;
                j--;
            }
        }
        return ans;
    }
};