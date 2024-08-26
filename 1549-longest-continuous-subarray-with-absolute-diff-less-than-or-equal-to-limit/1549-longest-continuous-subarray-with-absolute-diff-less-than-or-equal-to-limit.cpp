class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> inc;  // Monotonic increasing deque
        deque<int> dec;  // Monotonic decreasing deque
        int maxLength = 0, left = 0;

        for (int i = 0; i < nums.size(); i++) {
            int el = nums[i];
            
            while (!inc.empty() && el < inc.back()) {
                inc.pop_back();
            }
            inc.push_back(el);

            while (!dec.empty() && el > dec.back()) {
                dec.pop_back();
            }
            dec.push_back(el);

            while (dec.front() - inc.front() > limit) {
                if (nums[left] == dec.front()) {
                    dec.pop_front();
                }
                if (nums[left] == inc.front()) {
                    inc.pop_front();
                }
                left++;
            }
            maxLength = max(maxLength,i-left+1);
        }

        return maxLength;
    }
};
