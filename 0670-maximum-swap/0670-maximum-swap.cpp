class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int max_index=s.size()-1;
        int swap1=-1;
        int swap2=-1;
        for(int i=s.size()-2;i >=0;i--){
            if(s[i] > s[max_index]){
                max_index=i;
            }
            else if(s[i] < s[max_index]){
                swap1=i;
                swap2=max_index;
            }
        }
        if(swap1 != -1 and swap2 != -1) swap(s[swap1],s[swap2]);
        return stoi(s);
    }
};