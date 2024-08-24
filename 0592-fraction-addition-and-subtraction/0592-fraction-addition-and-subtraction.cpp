#include<bits/stdc++.h>
class Solution {
public:
    int find_lcm(int a,int b){
        return (a*b)/(__gcd(a,b));
    }
    string fractionAddition(string exp) {
        int n=exp.size();
        int lcm=1;
        for(int i=0;i<=n;i++){
            if(exp[i]=='/'){
                if(i+2 < n and exp[i+2] !='+' and exp[i+2] !='-') {
                    lcm=find_lcm(lcm,10*(exp[i+1]-'0')+(exp[i+2]-'0'));
                }
                else lcm=find_lcm(lcm,exp[i+1]-'0');
                i++;
            }
        }
        int ans=0;
        for(int i=0;i< exp.size();i++){
            int curr=0;
            int temp=0;
            if(exp[i]=='/'){
                if(exp[i+2] >='0' and exp[i+2] <='9'){
                    temp=lcm/((exp[i+1]-'0')*10+(exp[i+2]-'0'));
                }
                else temp=lcm/(exp[i+1]-'0');
                bool flag=false;
                if(i-2 >=0 and exp[i-2] >='0' and exp[i-2]<='9') {
                    curr=temp*((exp[i-2]-'0')*10+(exp[i-1]-'0'));
                    if(i-3 >=0){
                        if(exp[i-3]=='-') ans -=curr;
                        else ans +=curr;
                        flag=true;
                    }
                    else{
                        ans +=curr;
                        flag=true;
                    }
                }
                else {
                    curr=temp*(exp[i-1]-'0');
                }
                if(flag==false){
                    if(i-2 >=0){
                        if(exp[i-2]=='+') ans +=curr;
                        else ans -=curr;
                    }
                    else ans +=curr;
                }
            }
        }
        int extra=__gcd(lcm,ans);
        int ans1=ans/extra;
        int ans2=lcm/extra;
        if(ans2 <0) {
            ans2 *=-1;
            ans1=-ans/extra;
        }
        return to_string(ans1)+"/"+to_string(ans2);
    }
};