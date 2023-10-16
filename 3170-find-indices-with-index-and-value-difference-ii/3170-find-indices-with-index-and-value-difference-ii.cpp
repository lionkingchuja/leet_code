class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) {
        int n=nums.size();
        int mini=0;
        for(int i=0;i<n-id;i++){
            if(nums[i] <nums[mini]) mini=i;
            if(abs(nums[mini]-nums[i+id])>=vd) return{mini,i+id};
        }
        int maxi=0;
        for(int i=0;i<n-id;i++){
            if(nums[i] >nums[maxi]) maxi=i;
            if(abs(nums[maxi]-nums[i+id])>=vd) return{maxi,i+id};
        }
        return {-1,-1};
    }
};