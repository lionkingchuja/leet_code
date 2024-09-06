class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int size=n+m;
        int sum=0;
        for(int i=0;i< m;i++) sum+=rolls[i];
        int total_sum=mean*size;
        int remain_sum=total_sum-sum;
        vector<int>ans(n,0);
        cout<<remain_sum<<endl;
        int a=remain_sum % n;
        int b=remain_sum / n;
        if(remain_sum <= 0 or b >6 or b<=0) return {};
        vector<int> res(n,b);
        for(int i=1; i<=a; i++) {
            res[i]++;
            if(res[i] >6 or res[i] <=0) return {};
        }
        return res;
    }
};