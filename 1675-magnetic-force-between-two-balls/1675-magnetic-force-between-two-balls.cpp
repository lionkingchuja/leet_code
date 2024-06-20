class Solution {
public:
    bool Allocation(int minval,vector<int>& position, int m){
        int ballplaced=1;
        int lastpos=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-lastpos >=minval){
                ballplaced++;
                lastpos=position[i];
            }
            if(ballplaced >=m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int lo=1;
        int hi=position[position.size()-1]-position[0];
        int ans=0;
        while(lo<=hi){
            int mid=lo +(hi-lo)/2;
            if(Allocation(mid,position,m)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};