class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        
        int ans=0;
        for(int i=1;i<n-1;i++){
            int j=0;
            int k=i+1;
            int cnt1=0;
            while(j<i){
                if(rating[j] < rating[i]) cnt1++;
                j++;
            }
            int cnt2=0;
            while(k<n){
                if(rating[i] < rating[k]) {
                    cnt2++;
                }
                k++;
            }
            ans +=(cnt1*cnt2)+(i-cnt1)*(n-cnt2-1-i);
        }
        
        return ans;
    }
};