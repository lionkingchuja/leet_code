class Solution {
public:
    bool judgeSquareSum(int c) {
        int a=sqrt(c);
        int b=c-(a*a);
        int rem=sqrt(b);
        cout<<a<<endl;
        cout<<rem<<" "<<b;
        if(rem*rem == b) return true;
        for(int i=1;i<=a;i++){
            int y=c-i*i;
            int z=sqrt(y);
            if(z*z==y) return true;
        }
        return false;
    }
};