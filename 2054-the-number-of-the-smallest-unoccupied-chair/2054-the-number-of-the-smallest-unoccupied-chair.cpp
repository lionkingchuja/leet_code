class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int,int>>vp;
        for(int i=0;i<times.size();i++){
            vp.push_back({times[i][0],i});
        }
        sort(vp.begin(),vp.end());

        priority_queue<int,vector<int>,greater<int>>time;
        for(int i=0;i< times.size();i++) time.push(i);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto i:vp){
            int start=i.first;
            int person=i.second;

            while(!pq.empty() and pq.top().first <= start){
                time.push(pq.top().second);
                pq.pop();
            }

            int chair=time.top();
            time.pop();

            if(person == targetFriend) return chair;
            pq.push({times[person][1],chair});
        }
        return -1;
    }
};