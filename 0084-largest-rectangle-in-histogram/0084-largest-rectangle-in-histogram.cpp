class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prev;
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            if(st.empty()) prev.push_back(-1);
            else if(!st.empty() and st.top().first <heights[i]) prev.push_back(st.top().second);
            else if(!st.empty() and st.top().first >= heights[i]){
                while(!st.empty() and st.top().first >= heights[i]) st.pop();
                if(st.empty()) prev.push_back(-1);
                else prev.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        vector<int>next;
        stack<pair<int,int>>st1;
        for(int i=n-1;i>=0;i--){
            if(st1.empty()) next.push_back(n);
            else if(!st1.empty() and st1.top().first <heights[i]) next.push_back(st1.top().second);
            else if(!st1.empty() and st1.top().first >= heights[i]){
                while(!st1.empty() and st1.top().first >= heights[i]) st1.pop();
                if(st1.empty()) next.push_back(n);
                else next.push_back(st1.top().second);
            }
            st1.push({heights[i],i});
        }
        reverse(next.begin(),next.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int width=next[i]-prev[i]-1;
            int area=heights[i]*width;
            ans=max(ans,area);
        }
        return ans;
    }
};