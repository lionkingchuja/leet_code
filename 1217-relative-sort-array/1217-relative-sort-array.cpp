class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        vector<int>flag(n,false);
        vector<int>v;
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<arr1.size();j++){
                if(arr2[i]==arr1[j]){
                   v.push_back(arr1[j]);
                   flag[j]=true;
                }
            }
        }
        vector<int>v1;
        for(int i=0;i<flag.size();i++) if(flag[i]==false) v1.push_back(arr1[i]);
        sort(v1.begin(),v1.end());
        for(auto i:v1) v.push_back(i);
        return v;
    }
};