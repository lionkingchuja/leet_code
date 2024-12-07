class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int i=0;int j=0;
        while(i < n || j< n){

            while(i<n and start[i] =='_') i++;
            while(j<n and target[j] =='_') j++;
            if(start[i] !=target[j]) return false;
            if(start[i]=='L'){
                if(j>i) return false;
            }
            if(start[i]=='R'){
                if(i>j) return false;
            }
            i++;
            j++;
        }
        return true;
    }
};