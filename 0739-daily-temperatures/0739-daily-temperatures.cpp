class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n=a.size();
        stack<pair<int,int>>st;
        vector<int>v;
        for(int i=n-1;i>=0;i--){
            if(st.empty()) v.push_back(0);
            else if(!st.empty() and st.top().first >a[i]) v.push_back((st.top().second)-i);
            else if(!st.empty() and st.top().first <=a[i]){
                while(!st.empty() and st.top().first <=a[i]){
                    st.pop();
                }
                if(st.empty()) v.push_back(0);
                else v.push_back(st.top().second-i);
            }
            st.push({a[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
};