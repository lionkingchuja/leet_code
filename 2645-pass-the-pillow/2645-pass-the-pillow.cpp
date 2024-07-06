class Solution {
public:
    int passThePillow(int n, int time) {
        int quotient = time / (n - 1);
        return quotient % 2 == 0 ? (time % (n - 1) + 1) : (n - time % (n - 1));
    }
};