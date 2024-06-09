class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int sum=0;
        int ans=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
            int rem=sum % k;
            if(rem <0) rem +=k;
            cout<<rem<<" "<<sum%k<<endl;
            if(m.find(rem) !=m.end()){
                ans +=m[rem];
                m[rem] +=1;
            }
            else m[rem]=1;
        }
        return ans;
    }
};