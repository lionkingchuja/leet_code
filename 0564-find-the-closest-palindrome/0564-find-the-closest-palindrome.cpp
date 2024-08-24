class Solution {
public:
    string nearestPalindromic(string s) {
        int n=s.size();
        //case-1
        if(s=="1") return "0";
        //case-2
        string pre=s.substr(0,(n+1)/2);
        long long prenum=stoll(pre);

        set<string>results;
        for(int i:{-1,0,1}){
            string new_string=to_string(prenum+i);
            string temp;
            if(n % 2==0) temp=new_string + string(new_string.rbegin(),new_string.rend());
            else temp=new_string + string(new_string.rbegin()+1,new_string.rend());
            results.insert(temp);
        }
        results.erase(s);
        //case-3
        results.insert(to_string(static_cast<long long>(pow(10,n)+1)));
        //case-4
        results.insert(to_string(static_cast<long long>(pow(10,n-1)-1)));

        long long num=stoll(s),diff=LLONG_MAX;
        string ans;
        
        for(auto str:results){
            long long tempnum=stoll(str);
            long long tempdiff=abs(num-tempnum);

            if(tempdiff < diff or (tempdiff==diff and tempnum < stoll(ans))){
                ans=str;
                diff=tempdiff;
            }
        }
        return ans;
    }
};