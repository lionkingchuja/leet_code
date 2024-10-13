class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int maxVal = INT_MIN;
        // Push the first element of each list into the heap, and track the max value
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});  // {element, listIndex, elementIndex}
            maxVal = max(maxVal, nums[i][0]);
        }

        // Initialize the range with maximum possible values
        vector<int> minRange = {0, INT_MAX};

        while (!pq.empty()) {
            // Extract the minimum element from the heap
            vector<int> top = pq.top();
            pq.pop();
            int minElement = top[0], listIndex = top[1], elementIndex = top[2];

            // Update the smallest range if a smaller one is found
            if (maxVal - minElement < minRange[1] - minRange[0]) {
                minRange[0] = minElement;
                minRange[1] = maxVal;
            }
            // If this list is exhausted, break the loop
            if (elementIndex == nums[listIndex].size() - 1) {
                break;
            }
            // Get the next element from the same list and push it into the heap
            int nextElement = nums[listIndex][elementIndex + 1];
            pq.push({nextElement, listIndex, elementIndex + 1});

            // Update the max value if necessary
            maxVal = max(maxVal, nextElement);
        }
        return minRange;
        
    }
};