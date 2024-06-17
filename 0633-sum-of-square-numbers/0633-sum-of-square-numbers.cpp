class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0) return true;
        int a=sqrt(c);
        for(int i=1;i<=a;i++){
            int y=c-i*i;
            int z=sqrt(y);
            if(z*z==y) return true;
        }
        return false;
    }
};