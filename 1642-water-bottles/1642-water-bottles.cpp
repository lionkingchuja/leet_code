class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int temp=numBottles / numExchange;
        int rem=numBottles % numExchange;
        ans +=temp;
        int total=temp+rem;
        while(total >=numExchange){
            rem=total % numExchange;
            total =total / numExchange;
            ans +=total;
            total =total+rem;
        }
        return ans;
    }
};