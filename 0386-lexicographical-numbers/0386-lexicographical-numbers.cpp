class Solution {
public:
    static bool compare(int a,int b){
        string s1=to_string(a);
        string s2=to_string(b);

        return s1 < s2;
    }
    vector<int> lexicalOrder(int n) {
        vector<int>v;
        for(int i=1;i<=n;i++) v.push_back(i);
        sort(v.begin(),v.end(),compare);
        return v;
    }
};