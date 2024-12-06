class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int,int>m;
        for(int i=1;i<=n;i++){
            m[i]++;
        }
        for(auto i:banned){
            m[i]--;
            if(m[i]==0) m.erase(i);
        }
        
        int curr_sum=0;
        int cnt=0;
        for(auto i:m){
            if(i.second >0){
                curr_sum +=i.first;
                cnt++;
                if(curr_sum > maxSum) return cnt-1;
            }
        }
        return cnt;
    }
};