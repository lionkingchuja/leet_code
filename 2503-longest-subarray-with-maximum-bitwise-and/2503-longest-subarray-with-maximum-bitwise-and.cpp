class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0, count = 0, maxCount = 0;

        for(int i = 0; i < nums.size(); i++) {
            maxVal = max(maxVal, nums[i]);
        }

        for(int i = 0; i < nums.size(); i++) {
            if(maxVal == nums[i]) {
                count++;
            } else {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }

        maxCount = max(maxCount, count);
        // if(maxCount == 0) {
        //     return 1;
        // }
        return maxCount;
    }
};
