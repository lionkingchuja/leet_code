class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0;
        int one=0;
        int two=0;

        for(auto i:nums){
            if(i==0) zero++;
            else if(i==1) one++;
            else two++;
        }

        for(int i=0;i<nums.size();i++){
            if(zero >0){
                nums[i]=0;
                zero -=1;
            }
            else if(one >0){
                nums[i]=1;
                one -=1;
            }
            else {
                nums[i]=2;
                two -=1;
            }
        }
    }
};