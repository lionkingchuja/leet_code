class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());

        int cnt=skill.size()/2;
        int i=0;
        int j=skill.size()-1;
        int sum=skill[i]+skill[j];
        long long ans=skill[i]*skill[j];
        i++;j--;
        while(i<j){
            int add=skill[i]+skill[j];
            if(add !=sum) return -1;
            ans +=(long long)(skill[i]*skill[j]);
            i++;
            j--;
        }
        return ans;
    }
};