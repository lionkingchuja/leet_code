class trie{
public:
    trie* next[26];
    bool flag;
    trie(){
        flag=false;
        for(int i=0;i<26;i++) next[i]=NULL;
    }
};

class Solution {
    trie* root=new trie(); //Root node of the trie
    public:
    void insert(string &word){
        trie* curr=root;
        for(char c:word){
            if(!curr->next[c-'a']) curr->next[c-'a']=new trie();
            curr=curr->next[c-'a'];
        }
        curr->flag=true;
    }

    string search(string &word){
        trie* curr=root;
        string s;
        for(int i=0;i<word.size();i++){
            if(!curr->next[word[i]-'a']){
                if(curr->flag) return s;
                return word;
            }
            s +=word[i];
            curr=curr->next[word[i]-'a'];
            if(curr->flag) return s;
        }
        return s;
    }
    public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans,temp;
        for(auto i:dictionary) insert(i);

        for(auto c:sentence){
            if(c==' '){
               ans +=search(temp);
               ans +=' ';
               temp.clear();
            }
            else{
                temp +=c;
            }
        }
        ans +=search(temp);
        
        return ans;
    }
};