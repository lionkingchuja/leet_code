class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end())) return true;
        int n=nums.size();
        vector<int>v(n);
        for(int i=0;i<n;i++){
            int temp=nums[i];
            string ans="";
            while(temp>0){
                ans +=(temp %2+'0');
                temp /=2;
            }
            int cnt=0;
            for(int i=0;i<ans.size();i++){
                if(ans[i]=='1') cnt++;
            }
            v[i]=cnt;
        }
        for(auto i:v) cout<<i<<" ";
        cout<<endl;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(nums[j] > nums[j+1]) {
                    if(v[j]==v[j+1]) {
                        swap(nums[j],nums[j+1]);
                        swap(v[j],v[j+1]);
                    }
                }
            }
        }
        if(is_sorted(nums.begin(),nums.end())) return true;
        else return false;
    }
};