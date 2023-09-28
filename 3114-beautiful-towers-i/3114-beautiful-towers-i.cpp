class Solution {
public:
    #define ll long long
    long long maximumSumOfHeights(vector<int>& a) {
        int n=a.size();
        ll sum=0;
        for(ll i=0;i<n;i++){
            ll ans =a[i];
            int prev=a[i];
            for(ll j=i+1;j<n;j++){
                prev=min(prev,a[j]);
                ans +=prev;
            }
            prev=a[i];
            for(ll j=i-1;j>=0;j--){
                prev=min(prev,a[j]);
                ans +=prev;
            }
            sum=max(ans,sum);
        }
        return sum;
    }
};