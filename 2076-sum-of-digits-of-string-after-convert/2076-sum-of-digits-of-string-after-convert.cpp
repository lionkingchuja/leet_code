class Solution {
public:
    int getLucky(string s, int k) {
        int temp=0;
        for(auto i:s) {
            int curr=i-'a'+1;
            while(curr >0){
                temp +=curr %10;
                curr /=10;
            }
        }
        int sum=temp;
        k--;
        while(k >0){
            sum=0;
            while(temp >0){
                sum +=temp%10;
                temp /=10;
            }
            temp=sum;
            k--;
        }
        return sum;
        
    }
};