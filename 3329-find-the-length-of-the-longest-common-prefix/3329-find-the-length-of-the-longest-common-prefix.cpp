class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        map<string,int> mp;

        vector<string> st;

        for(auto it : arr1){
            string temp= to_string(it);
            string s;

            for(int i=0; i<temp.length(); i++){
                s.push_back(temp[i]);
                // st.push_back(s);
                mp[s]++;

            }
        }

        for(auto it : arr2){
            string temp= to_string(it);
            string s;

            for(int i=0; i<temp.size(); i++){
                s.push_back(temp[i]);
                st.push_back(s);
            }
        }

        sort(st.begin(), st.end());
        int maxi= INT_MIN;

        for(int i=0; i<st.size(); i++){
           if(mp.find(st[i])!= mp.end()){
            maxi= max(maxi, (int)st[i].size());
           } 
        }
        if(maxi==INT_MIN) return 0;
        return maxi;
    }
};