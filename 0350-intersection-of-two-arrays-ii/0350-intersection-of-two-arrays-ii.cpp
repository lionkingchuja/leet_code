class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<bool>flag(nums2.size(),false);
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j] and flag[j]==false){
                    ans.push_back(nums1[i]);
                    flag[j]=true;
                    break;
                }
            }
        }
        return ans;
    }
};