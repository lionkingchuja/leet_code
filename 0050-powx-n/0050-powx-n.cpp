class Solution {
public:
    double myPow(double x, int n) {
       double ans=1;
       long long num=n;
       if(n<0) num *=-1;
       while(num >0){
        if(num & 1){
            ans =ans *x;
            num =num-1;
        }
        else{
            x=x*x;
            num =num/2;
        }
       }
       if(n<0) ans=1.0/ans;
       return ans;
    }
};