class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;int cnt2=0;
        int el1,el2;
        for(int i=0;i<n;i++){
            if(cnt1==0 and el2 !=nums[i]){
                cnt1=1;
                el1=nums[i];
            }else if(cnt2==0 and el1 !=nums[i]){
                cnt2=1;
                el2=nums[i];
            }else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1) cnt1++;
            if(nums[i]==el2) cnt2++;
        }
        vector<int>v;
        if(cnt2 > n/3) v.push_back(el2);
        if(cnt1 > n/3 and el2 !=el1) v.push_back(el1);
        return v;
    }
};