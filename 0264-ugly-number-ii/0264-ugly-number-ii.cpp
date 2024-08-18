class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>prime={2,3,5};
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        unordered_set<long long>visited;
        pq.push(1);
        visited.insert(1);
        long long curr;
        for(int i=0;i<n;i++){
            curr=pq.top();
            pq.pop();
            for(auto i:prime){
                long long num=i*curr;
                if(visited.find(num) == visited.end()){
                    visited.insert(num);
                    pq.push(num);
                }
            }
        }
        return static_cast<int>(curr);
    }
};