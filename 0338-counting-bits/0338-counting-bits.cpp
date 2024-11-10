class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v;
        for(int i=0;i<=n;i++){
            int temp=i;
            int cnt=0;
            while(temp>0){
                cnt +=temp&1;
                temp=temp >>1;
            }
            v.push_back(cnt);
        }
        return v;
    }
};