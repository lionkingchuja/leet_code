class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans=0;
        for(auto i:m){
            if(i.second >1) ans +=((i.second-1)*(i.second))/2;
        }
        return ans;
    }
};