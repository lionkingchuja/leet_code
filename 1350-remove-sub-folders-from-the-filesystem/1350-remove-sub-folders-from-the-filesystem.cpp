class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>ans={folder[0]};

        for(int i=1;i<folder.size();i++){
            string temp=folder[i];
            if(temp.find(ans.back()+'/') !=0) ans.push_back(temp);
        }
        return ans;

    }
};