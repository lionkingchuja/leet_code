class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int>m;
        for (int i: hand) m[i]++;

        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &i :m) pq.push(i.first);

        while (!pq.empty()) {
            int start = pq.top();
            for (int i = 0; i < groupSize;i++) {
                int currentCard = start + i;
                if (m[currentCard] == 0) return false;
                if (--m[currentCard] == 0) {
                    //if (currentCard != pq.top()) return false;
                    pq.pop();
                }
            }
        }
        return true;
    }
};