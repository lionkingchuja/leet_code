class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        set<pair<int,pair<int,int>>>vp;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            string temp=to_string(nums[i]);
            string ans="";
            for(auto j:temp){
                int x=mapping[j-'0'];
                ans.push_back(x+'0');
            }   
            cout<<ans<<endl;
            vp.insert({stoi(ans),{i,nums[i]}});
        }
        for(auto i:vp){
            v.push_back(i.second.second);
        }
        return v;
    }
};