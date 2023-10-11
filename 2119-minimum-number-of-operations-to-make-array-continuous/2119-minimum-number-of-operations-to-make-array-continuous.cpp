class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<int>s;
        for(int i:nums) s.insert(i);
        vector<int>v;
        for(auto i:s) v.push_back(i);
        int right=0;
        int ans=INT_MAX;
        for(int i=0;i<v.size();i++){
            while(right< v.size() and (v[right] < (v[i]+n))) right+=1;
            ans=min(ans,(n-(right-i)));
        }
        return ans;
    }
};