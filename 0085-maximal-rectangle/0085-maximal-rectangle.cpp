class Solution {
public:
    int max_area_histogram(vector<int>&v){
        vector<int>left;
        stack<pair<int,int>>st;
        for(int i=0;i<v.size();i++){
            if(st.empty()) left.push_back(-1);
            else if(!st.empty() and st.top().first <v[i]) left.push_back(st.top().second);
            else if(!st.empty() and st.top().first >=v[i]){
                while(!st.empty() and st.top().first >=v[i]) st.pop();
                if(st.empty()) left.push_back(-1);
                else left.push_back(st.top().second);
            }
            st.push({v[i],i});
        }

        vector<int>right;
        stack<pair<int,int>>st1;
        for(int i=v.size()-1;i>=0;i--){
            if(st1.empty()) right.push_back(v.size());
            else if(!st1.empty() and st1.top().first <v[i]) right.push_back(st1.top().second);
            else if(!st1.empty() and st1.top().first >=v[i]){
                while(!st1.empty() and st1.top().first >=v[i]) st1.pop();
                if(st1.empty()) right.push_back(v.size());
                else right.push_back(st1.top().second);
            }
            st1.push({v[i],i});
        }
        reverse(right.begin(),right.end());
        int ans=INT_MIN;
        for(int i=0;i<v.size();i++){
            int width=right[i]-left[i]-1;
            ans=max(ans,v[i]*width);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>temp(m);
        int rec=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') temp[j]=(int)0;
                else temp[j] +=(int)matrix[i][j]-'0';
            }
            int final=max_area_histogram(temp);
            rec=max(final,rec);
        }
        return rec;
    }
};