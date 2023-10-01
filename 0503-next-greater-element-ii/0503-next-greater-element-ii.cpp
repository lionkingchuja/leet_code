class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;  //next greatest element
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            if(st.empty()) v.push_back(-1);
            else if(!st.empty() and st.top()>nums[i%n]) v.push_back(st.top());
            else if(!st.empty() and st.top()<=nums[i%n]){
                while(!st.empty() and st.top()<=nums[i%n]){
                    st.pop();
                }
                if(st.empty()) v.push_back(-1);
                else v.push_back(st.top());
            }
            st.push(nums[i%n]);
        }
        reverse(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<n;i++) ans.push_back(v[i]);
        return ans;
    }
};