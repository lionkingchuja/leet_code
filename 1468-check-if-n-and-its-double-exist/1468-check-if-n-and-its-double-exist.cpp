class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++) m[2*arr[i]]=i;
        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i]) !=m.end()){
                if(m[arr[i]]!=i) return true;
            }
        }
        return false;
    }

};