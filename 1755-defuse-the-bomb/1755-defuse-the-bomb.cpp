class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans(code.size(),0);
        if(k >0){
            for(int i=0;i<code.size();i++){
                int sum=0;
                int j=i+1;
                int len=k;
                while(len--){
                    sum +=code[j % code.size()];
                    j++;
                }
                ans[i]=sum;
            }
        }
        else if(k <0){
            for(int i=0;i<code.size();i++){
                int sum=0;
                int j=i-1;
                int len=abs(k);
                while(len--){
                    if(j<0) j +=code.size();
                    sum +=code[j];
                    j--;
                }
                ans[i]=sum;
            }
        }
        return ans;
    }
};