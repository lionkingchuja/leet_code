class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>m1;
        for(auto i:t) m1[i]++;
        int i=0;
        int j=0;int count=m1.size();int mi=INT_MAX;int start=0;
        string a="";
        if(t.length()>s.length()) return a;
        while(j<s.size()){
            if(m1.find(s[j])!=m1.end()){
                m1[s[j]]--;
                if(m1[s[j]]==0) count--;
                if(count==0){
                //mi=min(mi,j-i+1);
                    if(mi > (j-i+1)){
                        mi=j-i+1;
                        start=i;
                    }
                }
                // j++;
            }

            while(count==0){
                if(m1.find(s[i])!=m1.end()){
                        m1[s[i]]++;
                        if(m1[s[i]]==1) count++;
                }
                i++;
                if(count==0) {
                    if(mi > (j-i+1)){
                        mi=j-i+1;
                        start=i;
                    }
                }
            }
            j++;
        }
        if(mi==INT_MAX) return a;
        else return s.substr(start,mi);
    }
};