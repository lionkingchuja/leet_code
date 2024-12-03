class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string temp="";int j=1;
        for(int i=0;i< sentence.size();i++){
            if(sentence[i] !=' ') {
                temp +=sentence[i];
                if(temp.size()==searchWord.size()){
                    if(temp==searchWord) return j;
                }
            }
            else {
                temp="";
                j++;
            }
        }
        return -1;
    }
};