class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int>m;
        for(auto i:bills){
            if(i==10){
                m[10]++;
                if(m.find(5) != m.end()){
                    m[5]--;
                    if(m[5]==0) m.erase(5);
                }
                else return false;
            }
            else if(i==20){
                if(m[10] >=1 and m[5]>=1){
                    m[10]--;
                    m[5]--;
                    if(m[5]==0) m.erase(5);
                    if(m[10]==0) m.erase(10);
                }
                else if(m.find(5) !=m.end()){
                    if(m[5] >=3) m[5] -=3;
                    else return false;
                    if(m[5]==0) m.erase(5);
                }
                else return false;
            }
            else m[i]++;
        }
        cout<<m[5]<<" "<<m[10]<<endl;
        return true;
    }
};