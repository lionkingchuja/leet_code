class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_value=INT_MAX;
        for(int i=0;i<nums.size();i++){
            min_value=min(min_value,nums[i]);
        }
        return min_value;
    }
};