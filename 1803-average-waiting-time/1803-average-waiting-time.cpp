class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double ans=customers[0][1];
        int temp=customers[0][0]+customers[0][1];
        for(int i=1;i<n;i++){
            if(temp >= customers[i][0]){
                temp +=customers[i][1];
                ans +=(temp-customers[i][0]);
            }
            else{
                ans +=customers[i][1];
                temp=customers[i][0]+customers[i][1];
            }
            cout<<temp<<" "<<i<<endl;
        }
        return ans/n;
    }
};