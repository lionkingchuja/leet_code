class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
    string s="";
    int cnt3=0;
    int cnt2=0;
    int cnt1=0;
    int len=a+b+c;

    for(int i=0;i<len;i++){
        if((a==0 and b==0) or (b==0 and c==0) or (c==0 and a==0)) break;
        if(c >=b and c >=a){
            s +="c";
            cnt3++;
            c -=1;
            if(cnt3 ==2){
                cnt3=0;
                if(b >=a){
                    s +="b";
                    b -=1;
                    cnt2++;
                }
                else{
                    s +="a";
                    a -=1;
                    cnt1++;
                }
            }
        }
        else if(a >=b and a >=c){
            s +="a";
            cnt1++;
            a -=1;
            if(cnt1 ==2){
                cnt1=0;
                if(b >=c){
                    s +="b";
                    b -=1;
                    cnt2++;
                }
                else{
                    s +="c";
                    c -=1;
                    cnt3++;
                }
            }
        }
        else if(b >=a and b>=c){
            s +="b";
            cnt2++;
            b -=1;
            if(cnt2 ==2){
                cnt2=0;
                if(a >=c){
                    s +="a";
                    a -=1;
                    cnt1++;
                }
                else{
                    s +="c";
                    c -=1;
                    cnt3++;
                }
            }
        }
    }
    if(s.size()==len) return s;
    if(a==0 and b==0){
        s +="c";
        if(s.size()==len) return s;
        s +="c";
    }
    else if(b==0 and  c==0){
        s +="a";
        if(s.size()==len) return s;
        s +="a";
    }
    else {
        s +="b";
        if(s.size()==len) return s;
        s +="b";
    }
    return s;
  }
};