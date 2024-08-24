class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0) nums1=nums2;
        if(n==0){
            return;
        }

        vector<int>ans;
        int i=0;
        int j=0;

        while(i < m and j < n){
            if(nums1[i] <= nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j <n){
            ans.push_back(nums2[j]);
            j++;
        }
        for(int i=0;i<ans.size();i++){
            nums1[i]=ans[i];
        }
    }
};