class Solution {
public:
    bool detectCapitalUse(string word) {
        bool capital=false;
        bool small=false;
        int len=word.size();
        int i=0;
        if(word[i]>='A'&&word[i]<='Z'){
            i++;
        }
        for(i;i<len;i++){
            if(word[i]>='a'&&word[i]<='z'){
                small=true;
            }
            if(word[i]>='A'&&word[i]<='Z'){
                capital=true;
            }
        }
        if(len==1&&(word[0]>='A'&&word[0]<='Z')){
            return true;
        }
        return small^capital;
    }
};