class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) ans +=customers[i];
            else grumpy[i] *=customers[i];
        }
        //basically find maximum sum of subarray length minutes
        int i=0;
        int j=0;
        int mx=INT_MIN;
        int sum=0;
        while(j<n){
            sum +=grumpy[j];
            if(j-i+1 < minutes) j++;
            else if(j-i+1 == minutes){
                mx=max(sum,mx);
                j++;
            }
            else if(j-i+1 > minutes){
                sum -=grumpy[i];
                i++;
                if(j-i+1 == minutes){
                    mx=max(sum,mx);
                }
                j++;
            }
        }
        return ans+mx;
    }
};