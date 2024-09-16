class Solution {
public:
    int findMinDifference(vector<string>& time) {
        vector<int>minv(time.size());
        for(int i=0;i<time.size();i++){
            int h=stoi(time[i].substr(0,2));
            int m=stoi(time[i].substr(3));
            minv[i]=h*60+m;
        }

        sort(minv.begin(),minv.end());
        int mi=INT_MAX;
        for(int i=0;i<minv.size()-1;i++){
            mi=min(mi,minv[i+1]-minv[i]);
        }
        mi=min(mi,(24*60)-minv.back()+minv.front());
        return mi;
    }
};